Kada se klikne na figuru koja je movable sa desne strane ce biti oznaceno "Kliknuto polje".
Da bi se ponistio potez sa tom figurom potrebno je ponovo klikluti na to polje.
Dakle, ako se 2 puta klikne na isto polje to je kao da je potez krenuo iz pocetka.

pozicije:
	labelu label_xy i buttonu pushButton_xy dodeljuje se int xy. Sahovska tabla se posmatra kao niz duzine 64.
	Crni levi top(queensideCrniTop) ima poziciju 0, dok beli desni top(kingsideBeliTop) ima poziciju 63.



metodi:
	bool isFiguraMovable(int u)
		Figura na poziciji u se moze pomeriti, stim sto se ne racuna ovde da li je doslo
		do saha nakon pomeraja.
	bool isSah(QBoja b)
		Proverava da li je kralj date boje b napadnut.
	void priprema()
		Priprema movable figure za naredni potez.
	void figuraNapadaPolja(int u,bool* a)
		Upisuje u niz a true na pozicije koje figura, koja je na poziciji u, napada.
	bool isPoljeNapadnuto(int u,QBoja b)
		Proverava da li neka figura boje b napada polje u.
	void buttonsToPolja()
		Pamti trenutne movable figure u atributu polja da bi moglo da se "button enabled stanje" vrati na prethodno.
	void poljaToButtons()
		Setuje "button enabled stanje" na osnovu atributa polja.
	void narusavaLiRokadu(int u)
		Na osnovu pozicije u ili labela label_u ciji je sadrzaj upravo promenjen setuje odredjene bool atribute na false
		da bi se kasnije ustanovila mogucnost rokade.
	bool isRokadaAvailable(int u)
		Na osnovu bool atributa(klase Chess), sadrzaja mape(mapa) i fje poljeNapadnuto racuna da li je data rokada, odredjena
		na osnovu "pozicije kralja nakon rokade"(int u), moguca.
	void changeButtons(int u)
		Setuje "button enabled stanje" tj. na koje pozicije figura u moze da skoci.
