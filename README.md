# HelloOpenGl
Ganz tolles Projekt

## Genutzte Bibliotheken
- GLFW (https://www.glfw.org/)
- GLEW (http://glew.sourceforge.net/)
- GLM (https://glm.g-truc.net/0.9.9/index.html)

#GL Funktionen

## Erstellen eines Kontext/Window mit GLFW

- glfwInit()

- glfwWindowHint
-- Konfiguriert verschiedenste Parameter bzgl. des zu nutzenden OpenGL Kontext.

- glfwCreateWindow(Breite, Höhe, "Titel", (optional)Monitor, (optional)Share)
-- Erzeugt ein Fenster mit den gegebenen Einstellungen.

- glfwTerminate() 
-- Aufräumen von GLFW

- glfwMakeContextCurrent(Window*)
-- Verknüpft alle Operationen bzgl. OpenGL auf das übergebene Fenster.

- glfwWindowShouldClose(Window*)
-- Liefert die Information ob das Fenster geschlossen werden soll.

- glClearColor(Farbe)
-- Setzt die Farbe die im Fall von glClear(GL_COLOR_BUFFER_BIT) als Löschfarbe dient.

- glClear(Bits)
-- GL_COLOR_BUFFER_BIT (Löschfarbe) -> Löscht/Übermalt den Backbuffer mit dem gesetzten
Wert aus glClearColor() (Standardmäßig Schwarz)

- glfwSwapBuffers(Window*)
-- Tauscht den Backbuffer mit dem Frontbuffer aus.

- glfwPollEvents
-- Behandelt alle ausstehenden Input-Events (f.e. Keyevents, Mouseevents etc)

## Kompilieren eines Shaders
-- siehe Documentation: https://www.khronos.org/opengl/wiki/Shader_Compilation
