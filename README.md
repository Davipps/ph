# OperaRP
Servidor modalidad Roleplay creado sin base.

## Dependencias
* SA-MP 0.3.7-R2 Windows Server (http://files.sa-mp.com/samp037_svr_R2-1-1_win32.zip)
* Pawn Compiler (https://github.com/pawn-lang/compiler)
* Pawn stdlib (https://github.com/pawn-lang/pawn-stdlib)
* SA-MP stdlib ((https://github.com/pawn-lang/samp-stdlib)
* crashdetect (https://github.com/Zeex/samp-plugin-crashdetect)
* streamer (https://github.com/samp-incognito/samp-streamer-plugin)
* sscanf (https://github.com/maddinat0r/sscanf)
* MySQL-r41 (https://github.com/pBlueG/SA-MP-MySQL)
* Pawn.CMD (https://github.com/katursis/Pawn.CMD)
* Pawn.Regex (https://github.com/katursis/Pawn.Regex)
* YSI-Includes (https://github.com/pawn-lang/YSI-Includes)

### Instalación
1. Instala las **dependencias**
2. Crea las bases de datos
3. Importa el archivo [opera-rp.sql](opera-rp.sql) a su base de datos correspondiente
4. Edita la conexión mysql en el archivo [db.ini](db.ini)
5. Configura **_server.sfg_** si es nesesario
6. Ejecuta **_samp-server.exe_**

## Instalación si usa sampctl
```
sampctl package ensure
sampctl package build
```

Para iniciar la gamemode ```sampctl package run```
