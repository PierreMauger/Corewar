.name "La bourrasque"
.comment "Wait for it ..."

ld 6, r4

setup:
	live %2
    add r4, r4, r4
    xor r4, %512, r7
    zjmp %:start
    fork %:child
    live %251658255
    ld %0, r12
    zjmp %:setup

child:
    add r3, r4, r3
    ld %0, r12
    zjmp %:setup

start:
    st r1, 12
    ldi %0, r3, r14

code:
    live %1
    sti r14, %-511, r3
    zjmp %-511
