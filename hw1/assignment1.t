- init:
    run: rm -f assignment1
    blocker: true

- build:
    run: gcc -std=c99 -Wall -Werror assignment1.c -o assignment1  # timeout: 2
    blocker: true

- case_1900_1_1_1999:
    run: ./assignment1
    script:
        - pexpect.popen_spawn.PopenSpawn: "Enter date \\[year month day\\]: "  # timeout: 2
        - send: "1900 1 1"
        - pexpect.popen_spawn.PopenSpawn: "Enter end year: "                   # timeout: 2
        - send: "1999"
        - pexpect.popen_spawn.PopenSpawn: "It's a Monday.\r\n"                 # timeout: 2
        - pexpect.popen_spawn.PopenSpawn: "Same day-and-month on same weekday between 1901 and 1999: 14\r\n"  # timeout: 2
        - pexpect.popen_spawn.PopenSpawn: _EOF_  # timeout: 2
    exit: 0

- case_invalid_11_31:
    run: ./assignment1
    script:
        - pexpect.popen_spawn.PopenSpawn: "Enter date \\[year month day\\]: "  # timeout: 2
        - send: "2020 11 31"
        - pexpect.popen_spawn.PopenSpawn: "Invalid date.\r\n"                  # timeout: 2
        - pexpect.popen_spawn.PopenSpawn: _EOF_                                # timeout: 2
    exit: 1
