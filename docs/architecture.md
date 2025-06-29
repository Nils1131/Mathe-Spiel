# High-Level-Architektur

```
+-------+     +---------+     +--------------+
| main  +---->+ ui_menu +<----+ question_bank|
+-------+     +---------+     +--------------+
    |             |               |
    |             v               |
    |        +----------+         |
    |        |game_logic|---------+
    |        +----------+
    |             |
    v             v
+----------+  +---------+
|leaderboard| | storage |
+----------+  +---------+
```

## Module

### main
Das Hauptmodul dient als Einstiegspunkt des Programms. Es initialisiert die benötigten Komponenten und steuert den Ablauf der Anwendung.

### ui_menu
Dieses Modul stellt die Menüs und Eingabemasken für den Benutzer bereit. Es sammelt Benutzereingaben und übergibt diese an `game_logic` oder andere Subsysteme.

### question_bank
Hier werden alle Fragen verwaltet, aus denen das Spiel die Aufgaben zieht. Das Modul liefert zufällige oder gefilterte Fragen an die Spiel­logik.

### game_logic
Die zentrale Spiel­logik prüft Antworten, verwaltet den Spielfortschritt und berechnet die Punkte. Sie nutzt `question_bank` für neue Fragen und aktualisiert nach jeder Runde das `leaderboard`.

### leaderboard
Dieses Modul speichert und zeigt die besten Ergebnisse an. Es kann Ranglisten laden und nach dem Spiel die Ergebnisse aktualisieren.

### storage
`storage` kümmert sich um die dauerhafte Ablage von Daten, etwa im Dateisystem. Es wird vom `leaderboard` und ggf. von anderen Modulen genutzt, um Daten einzulesen oder zu speichern.

