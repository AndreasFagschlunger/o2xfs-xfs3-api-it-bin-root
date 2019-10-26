plugins {
    `cpp-library`
    `visual-studio`
}

import org.gradle.language.cpp.internal.DefaultCppBinary

library {
    targetMachines.add(machines.windows.x86)
    targetMachines.add(machines.windows.x86_64)
}

dependencies {
    api(project(":common"))
    implementation("eu.cen:cen-xfs-api:3.30")
}

val javaHome = System.getenv("JAVA_HOME") ?: System.getProperty("java.home")
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
