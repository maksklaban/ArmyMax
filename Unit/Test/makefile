all: test.out

test.out: main.o Spellcaster.o Wizard.o test_Wizard.o Unit.o State.o Spell.o Ability.o
	g++ -o test.out Spellcaster.o main.o Wizard.o test_Wizard.o Unit.o State.o Spell.o Ability.o&& ./test.out

main.o:
	g++ -c main.cpp

test_Wizard.o:
	g++ -c test_Wizard.cpp

Wizard.o:
	g++ -c ../Wizard.cpp

Ability.o:
	g++ -c ../Ability.cpp

Unit.o:
	g++ -c ../Unit.cpp

Spell.o:
	g++ -c ../Spell.cpp

Spellcaster.o:
	g++ -c ../Spellcaster.cpp

State.o:
	g++ -c /home/maks/Devclub/DZ6\ week/ArmyMax/State/State.cpp

clean:
	rm -f *.o && clear
