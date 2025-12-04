
#include"doctest.h"
#include"QuestionNumerique.h"
TEST_CASE("test de la class Question Numerique")
{
    QuestionNumerique q("QuestionNumerique", "3+4", 7, 0, 10);
    SUBCASE("Le constructeur focntionne")
    {
        CHECK(q.getIntitule() == "QuestionNumerique");
        CHECK(q.getTexte() == "3+4");
    }
    SUBCASE("Verification des bornes")
    {
        CHECK(q.max() == 10);
        CHECK(q.min() == 0);
    }
    SUBCASE("Gestion des reponse") {
        CHECK(q.verifierReponse("7") == true); //ok
        CHECK(q.verifierReponse("8") == false); // ofcrs wrong
        CHECK(q.verifierReponse("-1") == false);  // hors limite
        CHECK(q.verifierReponse("abc") == false); // not even a number
    }
}