plugins {
    `cpp-library`
    `visual-studio`
}

import org.gradle.language.cpp.internal.DefaultCppBinary

library {
    targetMachines.add(machines.windows.x86)
    targetMachines.add(machines.windows.x86_64)
}

val javaHome = System.getenv("JAVA_HOME") ?: System.getProperty("java.home")

val javah by tasks.registering(Exec::class) {
    val javah = (System.getenv("JAVA_HOME") ?: System.getProperty("java.home")) + "/bin/javah.exe"
    commandLine(javah, "-d", file("src/main/public/cdm"), "-cp", javaApi.asPath, "at.o2xfs.xfs.v3.cdm.Capabilities3IT")
}

val javaApi by configurations.creating
dependencies {
    implementation(project(":common"))
    implementation("eu.cen:cen-xfs-api:3.00")
    javaApi("at.o2xfs:o2xfs-xfs3-api-it:1.0-SNAPSHOT") {
        exclude(group = "at.o2xfs", module = "o2xfs-memory-impl-bin")
        exclude(group = "at.o2xfs", module = "o2xfs-xfs3-api-it-bin")
    }
}

val libIncludePath = files("$javaHome/include", "$javaHome/include/win32")

val mainLib: ProductionCppComponent = components.find{ it.name == "main" } as ProductionCppComponent
mainLib.binaries.whenElementFinalized({
    val binary = this as DefaultCppBinary;
    project.dependencies {
        if(binary.isOptimized) {
            add(binary.includePathConfiguration.name, libIncludePath)
        } else {
            add(binary.includePathConfiguration.name, libIncludePath)
        }
    }
})
