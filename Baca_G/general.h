int main() {
    HUMAN_CLASS human("murzyn1"),murzyn("murzyn2");
    murzyn.applyWinnerReward();
    CAESAR_CLASS * cezar;
    ARENA_CLASS * arena = new ARENA_CLASS(cezar);
    arena->fight(&human,&murzyn);
    arena->fight(&human,&murzyn);
}
int main() {
    CAESAR_CLASS caesar;
    ARENA_CLASS arena(&caesar);
    HUMAN_CLASS human1("human1");
    BEAST_CLASS beast1("beast1");
    BERSERKER_CLASS berserker1("berserker-human1", "berserker-beast1");

    HUMAN_CLASS dead("dead-human");

    dead.takeDamage(500);
    //cout<<dead.isAlive()<<endl;
    SQUAD_CLASS squad("squad");

    squad.addPlayer(&human1);
    squad.addPlayer(&beast1);
    squad.addPlayer(&berserker1);
    squad.addPlayer(&dead);

    squad.printParams();



    HUMAN_CLASS human2("human2");



    arena.fight(&squad, &human2);
}