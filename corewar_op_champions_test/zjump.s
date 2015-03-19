.name "zjump"
.comment "zjump"

l2:		sti r1, %:live, %1
		and r1, %0, r1
live:	live %1
		zjmp %:live2
live2:
		zjmp %:live

