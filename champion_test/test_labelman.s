.name "Label filled champion"
.comment "Le comment"
prev_label: zjmp %:end_label
brkp1: zjmp %:next_label
 zjmp %:prev_label
next_label:
 fork %:forkito
forkito:
 st r1, :brkp1
end_label:
 live %0
