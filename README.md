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

- glEnable(GL_DEPTH_TEST);
-- Schaltet die Tiefenberechnung ein -> Dadurch erzeugt man "Verdeckung".

- glClear(Bits)
-- GL_COLOR_BUFFER_BIT (Löschfarbe) -> Löscht/Übermalt den Backbuffer mit dem gesetzten
Wert aus glClearColor() (Standardmäßig Schwarz)
-- GL_DEPTH_BUFFER_BIT (Tiefenbuffer) -> Löscht die Tiefeninformationen des aktuellen Kontexts.


- glfwSwapBuffers(Window*)
-- Tauscht den Backbuffer mit dem Frontbuffer aus.

- glfwPollEvents
-- Behandelt alle ausstehenden Input-Events (f.e. Keyevents, Mouseevents etc)

## Kompilieren eines Shaders
-- siehe Documentation: https://www.khronos.org/opengl/wiki/Shader_Compilation


## Buffer

VertexArrayObject
- Wird verwendet um die Vertexlayout Informationen abzulegen.
- glGenVertexArrays(1, &m_vao);
- glBindVertexArray(m_vao);
- glEnableVertexAttribArray(VertexAttributeLocation::Position);

- glVertexAttribPointer(VertexAttributeLocation::Position, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)offsetof(Vertex, Position));
-- Definiert an welcher Stelle im Byteobject (hier struct Vertex), sich die Positionsdaten befinden. OffsetOf Position ergibt hier 0, da die
Position an 1. Stelle im Bytestream steht.

- glVertexAttribPointer(VertexAttributeLocation::VertexColor, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)offsetof(Vertex, Color));
-- Hier ergibt der OffsetOf "12" Bytes. Zuerst die Position mit 3 * float, und danach kommt die Color mit (4 * float).


VertexBufferObject
- Wird verwendet um die Vertexdaten von der CPU Seite an den GPU Speicher zu senden und dort abzulegen.
- glGenBuffers(count, unsigned int id);
- glBindBuffer(id);
- BufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

IndexBufferObject
- Wird verwendet um redundante Vertices zu sparen.
- glGenBuffers(count, unsigned int id);
- glBindBuffer(id);
- BufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);



## Lighting



