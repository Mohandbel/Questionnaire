#include "doctest.h"
#include "question_texte.h"


// test simple : on check juste si la comparaison marche
TEST_CASE("QuestionTexte : test basique") {
    QuestionTexte q("Q1", "Couleur du ciel ?", "bleu");

    CHECK(q.estBonneReponse("bleu") == true); //logique 
    CHECK(q.estBonneReponse("rouge") == false); // mdr non
}
