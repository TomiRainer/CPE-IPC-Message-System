# CPE-IPC-Message-System


# IPC Message System

## Überblick

Dieses Projekt beschäftigt sich mit **Inter-Process Communication (IPC)** und der Programmiersprache C.

IPC ermöglicht die Kommunikation und den Datenaustausch zwischen mehreren Prozessen. Dabei werden verschiedene Mechanismen verwendet, um Daten zu übertragen oder den Zugriff auf gemeinsam genutzte Ressourcen zu koordinieren.



## Verwendete Technologien

- Programmiersprache: C
- Prozessverwaltung: `fork()`, `wait()`
- IPC-Funktionen: Pipes, FIFO, Shared Memory und Semaphore

## Projektstruktur

| Ordner | Beschreibung |
|---|---|
| `FIFO/` | Kommunikation zwischen unabhängigen Prozessen über benannte Pipes |
| `Pipe/` | Kommunikation zwischen Prozessen über anonyme Pipes |
| `Semaphore/` | Synchronisation und Koordination von Prozessen |
| `Shared-Memory/` | Gemeinsamer Speicherbereich für den Datenaustausch zwischen Prozessen |

## Behandelte IPC-Methoden

### 1. Pipe (Unnamed Pipe)
- Anonymer Kommunikationskanal zwischen Prozessen
- Typischerweise zwischen Eltern- und Kindprozessen
- Wichtige Funktionen: `pipe()`, `read()`, `write()`, `fork()`

### 2. FIFO (Named Pipe)
- Benannter Kommunikationskanal
- Kommunikation auch zwischen unabhängigen Prozessen möglich
- Wichtige Funktionen: `mkfifo()`, `open()`, `read()`, `write()`

### 3. Shared Memory
- Mehrere Prozesse greifen auf denselben Speicherbereich zu
- Ermöglicht schnellen Datenaustausch
- Wichtige Funktionen: `shmget()`, `shmat()`, `shmdt()`, `shmctl()`

### 4. Semaphore
- Dienen zur Synchronisation von Prozessen
- Verhindern unkontrollierte gleichzeitige Zugriffe auf gemeinsame Ressourcen
- Schützen kritische Abschnitte
- Wichtige Funktionen: `semget()`, `semctl()`, `semop()`

