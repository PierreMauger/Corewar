.name "SANIC"
.comment "FAST AF BOI"

sti r1, %:trampoline, %1
st  r2, -7
fork %:zork_sender

p1:
    live %1
    ld %262144, r2
    ld %190055429, r3
    ld %190056197, r4
    ld %507, r5
    fork %:p2
    ld %190056453, r7
    ld %134443010, r8
    ld %0, r6
    zjmp %:trampoline

p2:
    ld %134443010, r2
    ld %101253622, r3
    ld %101253622, r4
    ld %101253622, r7
    ld %262144, r8
    ld %4, r6
    ld %0, r12

trampoline:
    live %1
    sti r3, %401, r6
    zjmp %395

zork_sender:
live %1
ld -5, r16
st r16, 485
st r1, 481
ld %150994944, r16 # zjump
ld %655310, r15
st r16, 466
st r15, 461
fork %:p1
sub r4, r4, r4
zjmp %440