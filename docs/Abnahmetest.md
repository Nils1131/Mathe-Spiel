# Manueller Abnahmetest

Diese Anleitung beschreibt, wie das Mathe-Spiel manuell getestet werden kann. Die folgenden Schritte führen durch das Kompilieren, Starten, Spielen und Zurücksetzen der Bestenliste.

## 1. Projekt bauen

Führe im Projektverzeichnis den folgenden Befehl aus, um das Spiel zu kompilieren:

```bash
make
```

![](img/test1.png)

## 2. Spiel starten

Nach erfolgreichem Build kann das Programm gestartet werden:

```bash
./bin/mathquiz        # unter Linux/macOS
bin\\mathquiz.exe    # unter Windows
```

Daraufhin erscheint das Hauptmenü des Spiels.

![](img/test2.png)

## 3. Runde spielen

Wähle im Hauptmenü die Option `1`, um eine Fragerunde zu starten. Beantworte die angezeigten Fragen. Nach Abschluss wirst du aufgefordert, deinen Namen für die Bestenliste einzugeben.

![](img/test3.png)

## 4. Bestenliste zurücksetzen

Um die gespeicherten Ergebnisse zu löschen, wähle im Hauptmenü die Option `3`. Nach der Bestätigung sollte die Meldung `Bestenliste zurückgesetzt.` erscheinen.

Damit ist der manuelle Abnahmetest abgeschlossen.
