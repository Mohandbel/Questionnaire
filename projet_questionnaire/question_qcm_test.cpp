#include "doctest.h"
#include "question_qcm.h"
// test QCM : je verifie juste si ça prend le bon numero
TEST_CASE("QuestionQCM : petit test") {

    std::array<std::string, 4> propositions = {
        "Rouge", "Bleu", "Vert", "Jaune"
    };

    QuestionQCM q("Q3", "Quelle est la couleur du ciel ?", propositions, 2);

    CHECK(q.estBonneReponse("2") == true); //bon
    CHECK(q.estBonneReponse("1") == false); // non
    CHECK(q.estBonneReponse("5") == false); // hors props
    CHECK(q.estBonneReponse("abc") == false); // also not a number
}
