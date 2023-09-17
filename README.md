
Repository klonen:
Verwenden Sie das git clone-Kommando, um das Repository, das Sie kopieren möchten, auf Ihren lokalen Computer zu klonen. Zum Beispiel:

git clone https://github.com/Nutzername/Repository-Name.git
Ersetzen Sie Nutzername durch den Benutzernamen des Repository-Besitzers und Repository-Name durch den Namen des Repositorys.


Ein neues Repository erstellen:
Erstellen Sie ein neues leeres GitHub-Repository, in das Sie den geklonten Code hochladen möchten. Sie können dies über die GitHub-Website tun.

Lokales Repository auf das neue Repository ausrichten:
Fügen Sie das neue Repository als Remote-URL zu Ihrem lokalen Repository hinzu. Verwenden Sie das git remote add-Kommando:

git remote add new-origin https://github.com/Ihr-Benutzername/Neues-Repository.git
Ersetzen Sie Ihr-Benutzername durch Ihren GitHub-Benutzernamen und Neues-Repository durch den Namen Ihres neuen Repositorys.

Änderungen hochladen:
Pushen Sie die Änderungen von Ihrem lokalen Repository in das neue Repository:

git push new-origin master
Hierbei wird der Code aus Ihrem geklonten Repository in das neue Repository hochgeladen.

Bitte beachten Sie, dass Sie die entsprechenden Berechtigungen für das neue Repository haben sollten, um Änderungen hochladen zu können. Wenn das neue Repository privat ist, stellen Sie sicher, dass Sie Zugriff darauf haben.
