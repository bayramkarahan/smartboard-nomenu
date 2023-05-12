#!/bin/bash
FILE="$HOME/Masaüstü/smartboard.desktop"
INIFILE="$HOME/smartboard.ini"

# init
# look for empty dir 

if [ -f $FILE ]; then
cp /usr/share/applications/smartboard.desktop $FILE
chmod 777 $FILE
chown $USER:$USER $FILE
     echo "dosya var"
else
cp /usr/share/applications/smartboard.desktop $FILE
chmod 777 $FILE
chown $USER:$USER $FILE
echo "Dosya Kopyalandı.."
   
fi

if [ -f $INIFILE ]; then
     echo "dosya var"
     cp /usr/share/e-tahta/smartboard.ini $INIFILE
     chmod 777 $INIFILE
     chown $USER:$USER $INIFILE
else
cp /usr/share/e-tahta/smartboard.ini $INIFILE
chmod 777 $INIFILE
chown $USER:$USER $INIFILE
echo "Dosya Kopyalandı.."
   
fi
exit

