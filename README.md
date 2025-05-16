# Cryptalk

Cryptalk ist ein experimentelles Netzwerkprotokoll, entwickelt als Lernprojekt zum Einstieg in C++ und zur praktischen Anwendung von Netzwerkprogrammierung. Ziel ist es, ein minimalistisches, eigenes Kommunikationsprotokoll zu definieren und zu implementieren – mit Fokus auf Struktur, Effizienz und Erweiterbarkeit.

## Zielsetzung

- Entwicklung eines eigenen binären Protokolls zur Datenübertragung
- Lernen von TCP-Socket-Programmierung in C++
- Grundverständnis für Puffer, Streams und Datenformate
- Vorbereitung auf eingebettete Kommunikation (z. B. mit Mikrocontrollern)
- Potenzieller Einsatz als Embedded-Interface oder Test-Server

## Features (geplant)

- Server-Client-Kommunikation via TCP
- Feste oder dynamische Datenrahmen
- Basis für Authentifizierung und Verschlüsselung (später)
- Logging empfangener Datenpakete

## Projektstruktur

cryptalk/
├── src/ # C++-Quellcode
│ ├── server.cpp
│ └── protocol.h
├── include/ # Header-Dateien
├── build/ # Kompilierte Binärdateien
└── README.md

markdown
Copy
Edit

## Abhängigkeiten

- C++17 oder höher
- POSIX-kompatibles Betriebssystem (Linux empfohlen)
- `g++` oder `clang++`
- CMake (optional)

## Kompilierung

```bash
g++ -std=c++17 -Wall -o build/server src/server.cpp