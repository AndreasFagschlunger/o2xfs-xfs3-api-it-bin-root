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