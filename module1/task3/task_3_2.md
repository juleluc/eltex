## Задания. Раздел 2
### 1.Создайте скрипт на языке bash с именем template_task.sh, делающий следующее:
`• При запуске дописывает в файл report_имя_скрипта_без_полного_пути.log в рабочем каталоге информацию: [PID] ДАТА ВРЕМЯ Скрипт запущен`  
`• Генерирует случайное число от 30 до 1800 и ждет такое количество секунд`   
`• Дописывает в файл report_имя_скрипта_без_полного_пути.log сообщение: [PID] ДАТА ВРЕМЯ Скрипт завершился, работал N минут`  

    root@eltex-practice2-pg2-v26:~ # cat template_task.sh 

    #!/bin/bash

    SCRIPT_NAME=$(basename "$0")

    LOG_FILE="report_${SCRIPT_NAME}.log"

    PID=$$

    DATETIME=$(date "+%Y-%m-%d %H:%M:%S")

    echo "[$PID] $DATETIME Скрипт запущен" >> "$LOG_FILE"

    MIN=30
    MAX=180

    GENERATE_SLEEP_TIME=$((MIN + RANDOM % (MAX - MIN + 1)))

    sleep "$GENERATE_SLEEP_TIME"

    TIME_TO_MINUTE=$((GENERATE_SLEEP_TIME / 60))

    DATETIME=$(date "+%Y-%m-%d %H:%M:%S")

    echo "[$PID] $DATETIME Скрипт завершился, работал $TIME_TO_MINUTE минут" >> "$LOG_FILE"
Содержимое log:

    root@eltex-practice2-pg2-v26:~ # cat report_template_task.sh.log   
    [34967] 2025-04-18 14:21:20 Скрипт запущен  
    [34967] 2025-04-18 14:22:01 Скрипт завершился, работал 0 минут  

### 2. Создайте скрипт на языке bash с именем observer.sh, читающий файл конфигурации со списком скриптов, проверяющим их наличие в списке работающих процессов и запускающих их в отключенном от терминала режиме (nohup) в случае отсутствия в нем. Информация о перезапуске дописывайте в файл observer.log

    root@eltex-practice2-pg2-v26:~ # cat observer.sh

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

    root@eltex-practice2-pg2-v26:~ # 


### 3. Настройте запуск observer.sh посредством cron по расписанию – 1 раз в минуту

    root@eltex-practice2-pg2-v26:~ # crontab -e
    no crontab for root - using an empty one
    Select an editor.  To change later, run 'select-editor'.

    1. /bin/nano        <---- easiest

    2. /usr/bin/vim.basic

    3. /usr/bin/vim.tiny

    4. /bin/ed

    Choose 1-4 [1]: 1
    crontab: installing new crontab
    root@eltex-practice2-pg2-v26:~ # crontab -l
    # Edit this file to introduce tasks to be run by cron.
    # 
    # Each task to run has to be defined through a single line
    # indicating with different fields when the task will be run
    # and what command to run for the task
    # 
    # To define the time you can provide concrete values for
    # minute (m), hour (h), day of month (dom), month (mon),
    # and day of week (dow) or use '*' in these fields (for 'any').
    # 
    # Notice that tasks will be started based on the cron's system
    # daemon's notion of time and timezones.
    # 
    # Output of the crontab jobs (including errors) is sent through
    # email to the user the crontab file belongs to (unless redirected).
    # 
    # For example, you can run a backup of all your user accounts
    # at 5 a.m every week with:
    # 0 5 * * 1 tar -zcf /var/backups/home.tgz /home/
    # 
    # For more information see the manual pages of crontab(5) and cron(8)
    # 
    # m h  dom mon dow   command
    * * * * * /bin/bash /root/observer.sh
    root@eltex-practice2-pg2-v26:~ # 

Синтаксис crontab:  
`минута час день месяц день_недели /путь/к/исполняемому/файлу`  

### 4. Скопируйте template_task.sh несколько раз с разными именами, добавьте в файл конфигурации observer.sh соответствующие записи об этих задачах.
    root@eltex-practice2-pg2-v26:~ # cp template_task.sh task1.sh
    root@eltex-practice2-pg2-v26:~ # cp template_task.sh task2.sh
    root@eltexpractice2-pg2-v26:~ # cp template_task.sh task3.sh
    root@eltex-practice2-pg2-v26:~ # 

Делаем все скрипты исполняемыми:  

    root@eltex-practice2-pg2-v26:~ # ls -l task1.sh task2.sh task3.sh
    -rw-r--r-- 1 root root 498 Apr 18 15:43 task1.sh
    -rw-r--r-- 1 root root 498 Apr 18 15:43 task2.sh
    -rw-r--r-- 1 root root 498 Apr 18 15:43 task3.sh
    root@eltex-practice2-pg2-v26:~ # chmod +x task1.sh 
    root@eltex-practice2-pg2-v26:~ # chmod +x task2.sh 
    root@eltex-practice2-pg2-v26:~ # chmod +x task3.sh 
    root@eltex-practice2-pg2-v26:~ # ls -l task1.sh task2.sh task3.sh
    -rwxr-xr-x 1 root root 498 Apr 18 15:43 task1.sh
    -rwxr-xr-x 1 root root 498 Apr 18 15:43 task2.sh
    -rwxr-xr-x 1 root root 498 Apr 18 15:43 task3.sh
    root@eltex-practice2-pg2-v26:~ # 

Создаем файл scripts.conf и добавляем исполняемые скрипты  

    root@eltex-practice2-pg2-v26:~ # cat scripts.conf 
    task1.sh
    task2.sh
    task3.sh
    root@eltex-practice2-pg2-v26:~ # ls

содержимое observer.log

    root@eltex-practice2-pg2-v26:~ # cat observer.log 
    Fri Apr 18 15:53:08 UTC 2025 перезапущен скрипт: task1.sh PID= 36065
    Fri Apr 18 03:54:01 PM UTC 2025 перезапущен скрипт: task2.sh PID= 36096
    Fri Apr 18 03:54:01 PM UTC 2025 перезапущен скрипт: task3.sh PID= 36102
    Fri Apr 18 03:56:01 PM UTC 2025 перезапущен скрипт: task1.sh PID= 36143
    Fri Apr 18 03:56:01 PM UTC 2025 перезапущен скрипт: task2.sh PID= 36149
    Fri Apr 18 03:56:01 PM UTC 2025 перезапущен скрипт: task3.sh PID= 36155
    root@eltex-practice2-pg2-v26:~ # 


### 5. Соберите статистику работы в виде набора файлов report_*.log, observer.log, приложите их вместе с исходными текстами скриптов в качестве отчета в виде сжатого архива tar. Не забудьте остановить процесс, удалив задачу в cron!
Удаляем задачу и останавливаем процессы.

    root@eltex-practice2-pg2-v26:~ # crontab -r 
    root@eltex-practice2-pg2-v26:~ # pkill -f task1.sh
    root@eltex-practice2-pg2-v26:~ # pkill -f task2.sh
    root@eltex-practice2-pg2-v26:~ # pkill -f task3.sh

Упаковываем все в архив.  

    root@eltex-practice2-pg2-v26:~ # tar czf report.tar.gz task1.sh task2.sh task3.sh template_task.sh observer.sh scripts.conf observer.log report_*.log


