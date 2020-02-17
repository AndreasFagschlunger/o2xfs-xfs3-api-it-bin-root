plugins {
    `maven-publish`
    `visual-studio`
}

group = "at.o2xfs"
version = "1.0-SNAPSHOT"

allprojects {
    repositories {
        maven {
            url = uri("https://repo.fagschlunger.co.at/libs-snapshot-local")
        }
        maven {
            url = uri("https://repo.fagschlunger.co.at/libs-release-local")
        }
        mavenCentral()
    }
}

tasks.register("javah") {
    val javah = (System.getenv("JAVA_HOME") ?: System.getProperty("java.home")) + "/bin/javah.exe"
    val jar = javaApi.first { it.name.startsWith("o2xfs-xfs3-api-it") }
    val classNames = mutableMapOf<String, MutableMap<String, MutableSet<String>>>()

    for(file in zipTree(jar).files.filter { it.name.endsWith("IT.class") && Regex("[a-z]{3}").matches(it.parentFile.name) }) {
        val serviceClassName = file.parentFile.name
        val serviceClassVersion = file.parentFile.parentFile.name
        val className = "at.o2xfs.xfs." + serviceClassVersion + "." + serviceClassName + "." + file.name.substring(0, file.name.lastIndexOf('.'))
        var classNamesPerVersion = classNames.get(serviceClassVersion)
        if(classNamesPerVersion == null) {
            classNamesPerVersion = mutableMapOf<String, MutableSet<String>>()
            classNames.put(serviceClassVersion, classNamesPerVersion)
        }
        var classNamesPerService = classNamesPerVersion.get(serviceClassName)
        if(classNamesPerService == null) {
            classNamesPerService = mutableSetOf<String>()
            classNamesPerVersion.put(serviceClassName, classNamesPerService)
        }
        classNamesPerService.add(className)
    }

    for(versionEntry in classNames.entries) {
        for(serviceEntry in versionEntry.value.entries) {
            println(versionEntry.key + "." + serviceEntry.key)
            val commandLine = mutableListOf(javah, "-d", "o2xfs-xfs" + versionEntry.key.toString().replace(Regex("[\\D]"), "") + "-api-it-bin/src/main/headers/" + serviceEntry.key, "-cp", javaApi.asPath)
            commandLine.addAll(serviceEntry.value)
            println(commandLine)
            Runtime.getRuntime().exec(commandLine.toTypedArray())
        }
    }
}

val javaApi by configurations.creating
dependencies {
    javaApi("at.o2xfs:o2xfs-xfs3-api-it:1.0-SNAPSHOT") {
        exclude(group = "at.o2xfs", module = "o2xfs-memory-impl-bin")
        exclude(group = "at.o2xfs", module = "o2xfs-xfs3-api-it-bin")
    }
}

tasks.register<Jar>("dist") {
    archiveFileName.set("o2xfs-xfs3-api-it-bin.jar")
    destinationDirectory.set(file("$buildDir/dist"))
    subprojects {
        dependsOn(tasks.withType<LinkSharedLibrary>())
        from("$buildDir/lib/main/release/x86") {
            include("*.dll")
            into("x86")
        }
        from("$buildDir/lib/main/release/x86-64") {
            include("*.dll")
            into("x86_64")
        }
    }
}

publishing {
    publications {
        create<MavenPublication>("mavenJava") {
            artifactId = "o2xfs-xfs3-api-it-bin"
            artifact(tasks["dist"])
        }
    }

    repositories {
        maven {
            url = if((version as String).endsWith("-SNAPSHOT")) uri("https://repo.fagschlunger.co.at/libs-snapshot-local") else uri("https://repo.fagschlunger.co.at/libs-release-local")
            credentials {
                val maven_username: String? by project
                val maven_password: String? by project
                username = maven_username
                password = maven_password
            }
        }
    }
}