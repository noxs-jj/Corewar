.name "zork"
.comment "I'M ALIIIIVE"

l2:		sti r1, %:l&ive&, %1
		and r1, %0, r1

l&ive&:	live %1
		zjmp %:l&ive&
