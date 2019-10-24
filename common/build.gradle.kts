plugins {
    `cpp-library`
    `visual-studio`
}

import org.gradle.language.cpp.internal.DefaultCppBinary

group = "at.o2xfs"
version = "1.0-SNAPSHOT"

val javaHome = System.getenv("JAVA_HOME") ?: System.getProperty("java.home")

library {
    linkage.set(listOf(Linkage.STATIC))
    targetMachines.set(listOf(machines.windows.x86, machines.windows.x86_64))
}

val libIncludePath = files("$javaHome/include", "$javaHome/include/win32", "C:/XFS SDKs/SDK310/INCLUDE")

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
