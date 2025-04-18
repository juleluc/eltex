  GNU nano 7.2                                  observer.sh                                           
#!/bin/bash

CONFIG_FILE='scripts.conf'

FILE_LOG='observer.log'

while read -r script; do
        if ! pgrep -f "bash $script" > /dev/null; then
                if [[ -x "$script" ]]; then
                nohup bash "$script" > /dev/null 2>&1 &
                echo "  $(date) перезапущен скрипт: $script PID= $!">> "$FILE_LOG"
                fi
        fi
done < "$CONFIG_FILE"
