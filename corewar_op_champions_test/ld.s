.name "ld"
.comment "ld"

add r1, r1, r2
add r2, r2, r2
add r2, r2, r3
add r3, r3, r3
add r3, r3, r3
add r3, r3, r3

ld %-1, r2
sti r2, r3, r3
