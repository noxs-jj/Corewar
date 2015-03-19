.name "death"
.comment "oh, my, what a scary project"

start:
	ld		%55576069, r6
	ld		%4, r5
	fork	%:core
	fork	%:prep
	zjmp	%:core
wall:
	st		r2, -450
	st		r2, -451
	st		r2, -452
	st		r2, -453
	st		r2, -454
	st		r2, -455
	st		r2, -456
	st		r2, -457
	st		r2, -458
	st		r2, -459
	st		r2, -460
	st		r2, -461
	st		r2, -462
	st		r2, -463
	st		r2, -464
	st		r2, -465
	st		r2, -466
	st		r2, -467
	st		r2, -468
	st		r2, -469
	st		r2, -470
	st		r2, -471
	st		r2, -472
	st		r2, -473
	st		r2, -474
	st		r2, -475
	st		r2, -476
	st		r2, -477
	st		r2, -478
	st		r2, -479
	st		r2, -480
	st		r2, -481
	st		r2, -482
	st		r2, -483
	st		r2, -484
	st		r2, -485
	st		r2, -486
	st		r2, -487
	st		r2, -488
	zjmp	%:survive
core:
	st		r1, 6
	live	%0
	fork	%:survive
	fork	%:core
	zjmp	%:wall
prep:
	st		r1, 32
	st		r1, 32
	st		r1, 32
	st		r1, 32
	st		r1, 32
	fork	%:imp
	zjmp	%:survive
survive:
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	zjmp	%:wall
imp:
	fork	%:imp
	st		r6, r5