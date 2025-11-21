#include "doctest.h"
#include "question_numerique.h"

// tests num
// j'essaye un peu tout : bon, faux, pas un nombre, etc

TEST_CASE("QuestionNumerique : test valeurs") {
    QuestionNumerique q("Q2", "3+4 ?", 7, 0, 10);

    CHECK(q.estBonneReponse("7") == true); //ok
    CHECK(q.estBonneReponse("8") == false); // ofcrs wrong
    CHECK(q.estBonneReponse("-1") == false);  // hors limite
    CHECK(q.estBonneReponse("abc") == false); // not even a number
}
