.name "Death2"
.comment "[...]"

init:
	fork %:live
	and %0, %1, r3
	zjmp %:core
live:
	st r1, 6
	live %0
	st r1, 6
	live %0
	zjmp %:live
wall:
	st		r2, -44
	st		r2, -53
	st		r2, -62
	st		r2, -71
	st		r2, -80
	st		r2, -89
	st		r2, -98
	st		r2, -107
	st		r2, -116
	st		r2, -125
	st		r2, -134
	st		r2, -143
	st		r2, -152
	st		r2, -161
	st		r2, -170
	st		r2, -179
	st		r2, -188
	st		r2, -197
	st		r2, -206
	st		r2, -215
	st		r2, -224
	st		r2, -233
	st		r2, -242
	st		r2, -251
	st		r2, -260
	st		r2, -269
	st		r2, -278
	st		r2, -287
	st		r2, -296
	st		r2, -305
	st		r2, -314
	st		r2, -323
	st		r2, -332
	st		r2, -341
	st		r2, -350
	st		r2, -359
	st		r2, -368
	st		r2, -377
	st		r2, -386
	st		r2, -395
	st		r2, -404
	st		r2, -413
	st		r2, -422
	st		r2, -431
	st		r2, -440
	st		r2, -449
	st		r2, -458
	st		r2, -467
	st		r2, -476
	st		r2, -485
	st		r2, -494
	and %0, %1, r3
	zjmp	%:wall
core:
	fork %:core2
	fork %:init
	and %0, %1, r3
	zjmp %:wall
core2:
	fork %:wall
	st r1, 6
	live %0
	fork %:core
	and %0, %1, r3
	zjmp %:core2
core3:
	fork %:wall
	st r1, 6
	live %0
	fork %:wall
	fork %:core
	and %0, %1, r3
	zjmp %:core3
	