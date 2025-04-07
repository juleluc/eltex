## Задания. Раздел 2  
Лог работы – команды и результаты в записать в файл practice2_part2.log  

### 1.Найдите все записи из лога загрузки, доступного через команду journalctl с опцией -b в первые
полторы секунды с момента загрузки  
 - -b - показать сообщения с момента определенной загрузки системы. По умолчанию используется последняя загрузка;  
 - --until- фильтрация по дате и времени;  
 - + относительное время от момента загрузки;  

            root@eltex-practice2-pg2-v26:~ # journalctl -b --until "+1.5s"
            Apr 07 02:16:15 localhost kernel: Linux version 6.8.0-57-generic (buildd@lcy02-amd64-040) (x86_64-linux-gnu-gcc-13 (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0, GN>
            Apr 07 02:16:15 localhost kernel: Command line: BOOT_IMAGE=/vmlinuz-6.8.0-57-generic root=/dev/mapper/ubuntu--vg-ubuntu--lv ro
            Apr 07 02:16:15 localhost kernel: KERNEL supported cpus:
            Apr 07 02:16:15 localhost kernel:   Intel GenuineIntel
            Apr 07 02:16:15 localhost kernel:   AMD AuthenticAMD
            Apr 07 02:16:15 localhost kernel:   Hygon HygonGenuine
            Apr 07 02:16:15 localhost kernel:   Centaur CentaurHauls
            Apr 07 02:16:15 localhost kernel:   zhaoxin   Shanghai  
            Apr 07 02:16:15 localhost kernel: BIOS-provided physical RAM map:
            Apr 07 02:16:15 localhost kernel: BIOS-e820: [mem 0x0000000000000000-0x000000000009fbff] usable
            Apr 07 02:16:15 localhost kernel: BIOS-e820: [mem 0x000000000009fc00-0x000000000009ffff] reserved
            Apr 07 02:16:15 localhost kernel: BIOS-e820: [mem 0x00000000000f0000-0x00000000000fffff] reserved
            Apr 07 02:16:15 localhost kernel: BIOS-e820: [mem 0x0000000000100000-0x00000000bffd9fff] usable
            Apr 07 02:16:15 localhost kernel: BIOS-e820: [mem 0x00000000bffda000-0x00000000bfffffff] reserved
            Apr 07 02:16:15 localhost kernel: BIOS-e820: [mem 0x00000000feffc000-0x00000000feffffff] reserved
            Apr 07 02:16:15 localhost kernel: BIOS-e820: [mem 0x00000000fffc0000-0x00000000ffffffff] reserved
            Apr 07 02:16:15 localhost kernel: BIOS-e820: [mem 0x0000000100000000-0x000000013fffffff] usable
            Apr 07 02:16:15 localhost kernel: BIOS-e820: [mem 0x000000fd00000000-0x000000ffffffffff] reserved
            Apr 07 02:16:15 localhost kernel: NX (Execute Disable) protection: active
            Apr 07 02:16:15 localhost kernel: APIC: Static calls initialized
            Apr 07 02:16:15 localhost kernel: SMBIOS 2.8 present.
            Apr 07 02:16:15 localhost kernel: DMI: QEMU Standard PC (i440FX + PIIX, 1996), BIOS rel-1.16.3-0-ga6ed6b701f0a-prebuilt.qemu.org 04/01/2014
            Apr 07 02:16:15 localhost kernel: Hypervisor detected: KVM
            Apr 07 02:16:15 localhost kernel: kvm-clock: Using msrs 4b564d01 and 4b564d00
            Apr 07 02:16:15 localhost kernel: kvm-clock: using sched offset of 107045243134 cycles
            Apr 07 02:16:15 localhost kernel: clocksource: kvm-clock: mask: 0xffffffffffffffff max_cycles: 0x1cd42e4dffb, max_idle_ns: 881590591483 ns
            Apr 07 02:16:15 localhost kernel: tsc: Detected 3399.996 MHz processor
            Apr 07 02:16:15 localhost kernel: e820: update [mem 0x00000000-0x00000fff] usable ==> reserved
            Apr 07 02:16:15 localhost kernel: e820: remove [mem 0x000a0000-0x000fffff] usable
            Apr 07 02:16:15 localhost kernel: AGP: No AGP bridge found
            Apr 07 02:16:15 localhost kernel: last_pfn = 0x140000 max_arch_pfn = 0x400000000
            Apr 07 02:16:15 localhost kernel: MTRR map: 4 entries (3 fixed + 1 variable; max 19), built from 8 variable MTRRs
            Apr 07 02:16:15 localhost kernel: x86/PAT: Configuration [0-7]: WB  WC  UC- UC  WB  WP  UC- WT  
            Apr 07 02:16:15 localhost kernel: last_pfn = 0xbffda max_arch_pfn = 0x400000000
            Apr 07 02:16:15 localhost kernel: found SMP MP-table at [mem 0x000f5450-0x000f545f]
            Apr 07 02:16:15 localhost kernel: RAMDISK: [mem 0x2fccb000-0x33e5cfff]
            Apr 07 02:16:15 localhost kernel: ACPI: Early table checksum verification disabled
            Apr 07 02:16:15 localhost kernel: ACPI: RSDP 0x00000000000F5250 000014 (v00 BOCHS )
            Apr 07 02:16:15 localhost kernel: ACPI: RSDT 0x00000000BFFE3BFC 000038 (v01 BOCHS  BXPC     00000001 BXPC 00000001)
            Apr 07 02:16:15 localhost kernel: ACPI: FACP 0x00000000BFFE39DE 000074 (v01 BOCHS  BXPC     00000001 BXPC 00000001)
            Apr 07 02:16:15 localhost kernel: ACPI: DSDT 0x00000000BFFDF040 00499E (v01 BOCHS  BXPC     00000001 BXPC 00000001)
            Apr 07 02:16:15 localhost kernel: ACPI: FACS 0x00000000BFFDF000 000040
            Apr 07 02:16:15 localhost kernel: ACPI: APIC 0x00000000BFFE3A52 000080 (v03 BOCHS  BXPC     00000001 BXPC 00000001)


### 2.Используя awk найдите все источники и их сообщения в файле auth.log (найдите его find), в названии источника удалите информацию об идентификаторе процесса при помощи sed, полученный результат отсортируйте по названию источника  
1. Найти файл auth.log  

    root@eltex-practice2-pg2-v26:~ # find /var/log -name "auth.log"
    /var/log/auth.log
2. Извлечение источника и сообщения, удаление [PID] из источника, сортировка по названию источника.   
    sed:  
     `s/что_заменять/на_что_заменять/опции` - замена символов, поддерживаются регулярные выражения;

    root@eltex-practice2-pg2-v26:~ # awk '{print $3, $4, $5, $6, $7, $8, $9, $10, $11} ' /var/log/auth.log | sed 's/\[[0-9]*\]//g' | sort
    (systemd): pam_unix(systemd-user:session): session opened for user root(uid=0) by root(uid=0)
    CRON: pam_unix(cron:session): session closed for user root  
    CRON: pam_unix(cron:session): session closed for user root  
    CRON: pam_unix(cron:session): session closed for user root  
    CRON: pam_unix(cron:session): session closed for user root  
    CRON: pam_unix(cron:session): session closed for user root  
    CRON: pam_unix(cron:session): session closed for user root  
    CRON: pam_unix(cron:session): session closed for user root  
    CRON: pam_unix(cron:session): session closed for user root  
    CRON: pam_unix(cron:session): session closed for user root  
    CRON: pam_unix(cron:session): session closed for user root  
    CRON: pam_unix(cron:session): session closed for user root  
    CRON: pam_unix(cron:session): session closed for user root  
    CRON: pam_unix(cron:session): session closed for user root  
    CRON: pam_unix(cron:session): session closed for user root  
    CRON: pam_unix(cron:session): session closed for user root  
    CRON: pam_unix(cron:session): session closed for user root  
    CRON: pam_unix(cron:session): session closed for user root  
    CRON: pam_unix(cron:session): session closed for user root  
    CRON: pam_unix(cron:session): session closed for user root  
    CRON: pam_unix(cron:session): session closed for user root  
    CRON: pam_unix(cron:session): session closed for user root  
    CRON: pam_unix(cron:session): session closed for user root  
    CRON: pam_unix(cron:session): session closed for user root  
    CRON: pam_unix(cron:session): session closed for user root  
    CRON: pam_unix(cron:session): session closed for user root  
    ....
    CRON: pam_unix(cron:session): session opened for user root(uid=0) by root(uid=0)
    CRON: pam_unix(cron:session): session opened for user root(uid=0) by root(uid=0)
    CRON: pam_unix(cron:session): session opened for user root(uid=0) by root(uid=0)
    CRON: pam_unix(cron:session): session opened for user root(uid=0) by root(uid=0)
    CRON: pam_unix(cron:session): session opened for user root(uid=0) by root(uid=0)
    CRON: pam_unix(cron:session): session opened for user root(uid=0) by root(uid=0)
    CRON: pam_unix(cron:session): session opened for user root(uid=0) by root(uid=0)
    CRON: pam_unix(cron:session): session opened for user root(uid=0) by root(uid=0)
    CRON: pam_unix(cron:session): session opened for user root(uid=0) by root(uid=0)
    CRON: pam_unix(cron:session): session opened for user root(uid=0) by root(uid=0)
    CRON: pam_unix(cron:session): session opened for user root(uid=0) by root(uid=0)
    polkitd: Acquired the name org.freedesktop.PolicyKit1 on the system bus
    polkitd: Acquired the name org.freedesktop.PolicyKit1 on the system bus
    polkitd: Finished loading, compiling and executing 6 rules 
    polkitd: Finished loading, compiling and executing 6 rules 
    polkitd: Loading rules from directory /etc/polkit-1/rules.d   
    polkitd: Loading rules from directory /etc/polkit-1/rules.d   
    polkitd: Loading rules from directory /usr/share/polkit-1/rules.d   
    polkitd: Loading rules from directory /usr/share/polkit-1/rules.d   
    sshd: Accepted publickey for root from 172.16.8.2 port 53340
    sshd: Server listening on :: port 22.  
    sshd: pam_unix(sshd:session): session opened for user root(uid=0) by root(uid=0)
    systemd-logind: New seat seat0.     
    systemd-logind: New seat seat0.     
    systemd-logind: New session 56 of user root.  
    systemd-logind: Watching system buttons on /dev/input/event0 (Power Button) 
    systemd-logind: Watching system buttons on /dev/input/event0 (Power Button) 
    systemd-logind: Watching system buttons on /dev/input/event1 (AT Translated Set
    systemd-logind: Watching system buttons on /dev/input/event1 (AT Translated Set



### 3.Для результата из предыдущего пункта найдите количество повторений для каждого источника и выведите их в виде списка «число_повторений источник», результат отсортируйте по убыванию количества повторений  

 `uniq -c подсчитывает количество повторений для каждого источника.`  
 `sort -nr сортирует по убыванию (-n — числовая сортировка, -r — в обратном порядке).`  


    root@eltex-practice2-pg2-v26:~ # awk '{print $3, $4, $5, $6, $7, $8, $9, $10, $11} ' /var/log/auth.log | sed 's/\[[0-9]*\]//g' | sort | uniq -c | sort -nr
        239 CRON: pam_unix(cron:session): session opened for user root(uid=0) by root(uid=0)
        239 CRON: pam_unix(cron:session): session closed for user root  
        2 systemd-logind: Watching system buttons on /dev/input/event1 (AT Translated Set
        2 systemd-logind: Watching system buttons on /dev/input/event0 (Power Button) 
        2 systemd-logind: New seat seat0.     
        2 polkitd: Loading rules from directory /usr/share/polkit-1/rules.d   
        2 polkitd: Loading rules from directory /etc/polkit-1/rules.d   
        2 polkitd: Finished loading, compiling and executing 6 rules 
        2 polkitd: Acquired the name org.freedesktop.PolicyKit1 on the system bus
        1 systemd-logind: New session 56 of user root.  
        1 sshd: pam_unix(sshd:session): session opened for user root(uid=0) by root(uid=0)
        1 sshd: Server listening on :: port 22.  
        1 sshd: Accepted publickey for root from 172.16.8.2 port 53340
        1 (systemd): pam_unix(systemd-user:session): session opened for user root(uid=0) by root(uid=0)

    root@eltex-practice2-pg2-v26:~ # 


### 4.В файле /etc/passwd найдите всех пользователей в системе, у которых установлен shell /usr/sbin/nologin и выведите их в виде списка: «UID, username, список его групп», отсортированный в обратном порядке по UID, cписок групп используйте из файла /etc/group  
`-F - разделитель полей, используется для разбиения текста на колонки;`  
`FNR - номер обрабатываемой строки в файле;`  
`NF - количество колонок в данной строке;`  

    root@eltex-practice2-pg2-v26:~ # awk -F: 'NR==FNR {if ($7 == "/usr/sbin/nologin") UID[$1]=$3; next} 
    {split($4, USERS, ","); for (i in USERS) if (USERS[i] in UID) print UID[USERS[i]], USERS[i], $1}' /etc/passwd /etc/group | sort -k1nr
    1003 user3 new_group
    103 syslog adm
    root@eltex-practice2-pg2-v26:~ #   


### 5.Найдите в результате вывода dmesg все строки, содержащие слово 'kernel‘  
`-i, - не учитывать регистр символов;`  

    root@eltex-practice2-pg2-v26:~ # dmesg | grep "kernel"
    [    0.060999] Booting paravirtualized kernel on KVM
    [    0.061361] Unknown kernel command line parameters "BOOT_IMAGE=/vmlinuz-6.8.0-57-generic", will be passed to user space.
    [    0.128821] Memory: 3933484K/4193760K available (22528K kernel code, 4444K rwdata, 14344K rodata, 4988K init, 4716K bss, 260016K reserved, 0K cma-reserved)
    [    0.588584] Loaded X.509 cert 'Build time autogenerated kernel key: 314db5b871207b67c6af73164cb9641e90a23972'
    [    3.768176] Loaded X.509 cert 'Build time autogenerated kernel key: 314db5b871207b67c6af73164cb9641e90a23972'
    [    3.792560] Freeing unused kernel image (initmem) memory: 4988K
    [    3.793405] Write protecting the kernel read-only data: 38912k
    [    3.794563] Freeing unused kernel image (rodata/data gap) memory: 2040K
    [   55.744056] systemd[1]: Listening on systemd-udevd-kernel.socket - udev Kernel Socket.
    [   55.758060] systemd[1]: Mounting sys-kernel-debug.mount - Kernel Debug File System...
    [   55.762924] systemd[1]: Mounting sys-kernel-tracing.mount - Kernel Trace File System...
    [   56.111426] systemd[1]: Mounted sys-kernel-debug.mount - Kernel Debug File System.
    [   56.112120] systemd[1]: Mounted sys-kernel-tracing.mount - Kernel Trace File System.
    [   56.126234] systemd[1]: Mounting sys-kernel-config.mount - Kernel Configuration File System...
    [   56.133809] systemd[1]: Mounted sys-kernel-config.mount - Kernel Configuration File System.
    root@eltex-practice2-pg2-v26:~ # 

### 6.Подсчитайте количество строк в файле /var/log/kern.log  
`-l количество строк в объекте`  

    root@eltex-practice2-pg2-v26:~ # wc -l /var/log/kern.log
    1463 /var/log/kern.log
    root@eltex-practice2-pg2-v26:~ # 


### 7.Отформатируйте вывод записей в /var/log/apt/history.log в следующем порядке, построчно:
Commandline: … ; Start-Date: … ; End-Date: …  

    root@eltex-practice2-pg2-v26:~ # awk '  /^Start-Date:/ {start=$0}  /^Commandline:/ {cmd=$0}  /^End-Date:/ {end=$0; print cmd "; " start "; " end} ' /var/log/apt/history.log 

    Commandline: /usr/bin/unattended-upgrade; Start-Date: 2025-04-02  06:40:57; End-Date: 2025-04-02  06:46:55
    Commandline: /usr/bin/unattended-upgrade; Start-Date: 2025-04-02  06:46:58; End-Date: 2025-04-02  06:47:03
    Commandline: /usr/bin/unattended-upgrade; Start-Date: 2025-04-02  06:47:05; End-Date: 2025-04-02  06:47:16
    Commandline: /usr/bin/unattended-upgrade; Start-Date: 2025-04-02  06:47:18; End-Date: 2025-04-02  06:47:24
    Commandline: /usr/bin/unattended-upgrade; Start-Date: 2025-04-02  06:47:26; End-Date: 2025-04-02  06:47:36
    Commandline: /usr/bin/unattended-upgrade; Start-Date: 2025-04-02  06:47:38; End-Date: 2025-04-02  06:47:45
    Commandline: /usr/bin/unattended-upgrade; Start-Date: 2025-04-02  06:47:46; End-Date: 2025-04-02  06:48:06
    Commandline: /usr/bin/unattended-upgrade; Start-Date: 2025-04-02  06:48:09; End-Date: 2025-04-02  06:48:26
    Commandline: /usr/bin/unattended-upgrade; Start-Date: 2025-04-03  06:44:57; End-Date: 2025-04-03  06:45:34
    Commandline: /usr/bin/unattended-upgrade; Start-Date: 2025-04-03  06:45:38; End-Date: 2025-04-03  06:45:44
    Commandline: /usr/bin/unattended-upgrade; Start-Date: 2025-04-05  06:03:08; End-Date: 2025-04-05  06:03:34
    Commandline: /usr/bin/unattended-upgrade; Start-Date: 2025-04-05  06:03:36; End-Date: 2025-04-05  06:03:44
    root@eltex-practice2-pg2-v26:~ # 

