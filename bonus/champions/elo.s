.name "Elotim"
.comment "Smol but gold"

sti r1, %:trampoline, %1
st  r2, -7

p1:
    live %4222
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
