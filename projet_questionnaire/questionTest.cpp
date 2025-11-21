#include "doctest.h"
#include "question.h"
// petite classe fake juste pr pouvoir instancier Question
// (vu que Question est abstraite et ça saoule)
class QuestionTestFake : public Question {
public:
    QuestionTestFake(const std::string& i, const std::string& t)
        : Question(i, t) {
    }

    bool estBonneReponse(const std::string&) const override {
        return true;
    }

    void afficherBonneReponse(std::ostream& os) const override {
        os << "OK";
    }
};

TEST_CASE("Test du constructeur Question") {
    QuestionTestFake q("Q1", "blabla test");

    CHECK(q.intitule() == "Q1");
    CHECK(q.texte() == "blabla test");
}
