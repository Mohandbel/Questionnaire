#include "doctest.h"
#include "doctest.h"
#include "EvaluationSecondeChance.h"
#include "QuestionTexte.h"
#include <memory>
#include <vector>

SCENARIO("fonctionnement de la seconde chance dans l evaluation") {

    GIVEN("evaluation avec une seule question") {
        std::vector<std::unique_ptr<Question>> questions;
        questions.push_back(std::make_unique<QuestionTexte>("Q1", "Capitale de la France ?", "Paris"));

        EvaluationSecondeChance eval(std::move(questions));
        bool afficherReponse = false;

        WHEN("utilisateur donne la bonne reponse immediatement") {
            bool resultat = eval.repondre("Paris", afficherReponse);

            THEN("succes est direct et on ne montre pas la solution") {
                REQUIRE(resultat == true);
                CHECK(afficherReponse == false);
                CHECK(eval.nombreBonnesReponses() == 1);
                CHECK(eval.nombreEssais() == 1);
            }
        }

        WHEN("l utilisateur se trompe une premiere fois") {
            bool resultat = eval.repondre("Lyon", afficherReponse);

            THEN("l utilisateur échoue mais la solution reste cachée (seconde chance)") {
                CHECK(resultat == false);
                CHECK(afficherReponse == false);
                CHECK(eval.nombreEssais() == 1);
            }
            AND_WHEN("l utilisateur donne la bonne réponse au deuxieme essai") {
                resultat = eval.repondre("Paris", afficherReponse);

                THEN("l évaluation compte une bonne reponse") {
                    CHECK(resultat == true);
                    CHECK(eval.nombreBonnesReponses() == 1);
                    CHECK(eval.nombreEssais() == 2);
                }
            }

            AND_WHEN("L'utilisateur se trompe encore une fois") {
                resultat = eval.repondre("Marseille", afficherReponse);
                THEN("L'échec est définitif et la solution est affichée") {
                    CHECK(resultat == false);
                    CHECK(afficherReponse == true);
                    CHECK(eval.nombreBonnesReponses() == 0);
                }
            }
        }
    }
}
SCENARIO("Réinitialisation de l'état entre les questions") {
    GIVEN("Une évaluation avec deux questions") {
        std::vector<std::unique_ptr<Question>> questions;
        questions.push_back(std::make_unique<QuestionTexte>("q1", "q1", "r1"));
        questions.push_back(std::make_unique<QuestionTexte>("q2", "q2", "r2"));
        EvaluationSecondeChance eval(std::move(questions));
        bool afficher;

        WHEN("L'utilisateur utilise sa 2e chance sur q1 et passe à q2") {
            eval.repondre("faux", afficher);
            eval.repondre("r1", afficher);
            eval.questionSuivante();

            THEN("La seconde chance doit être disponible pour Q2") {
                eval.repondre("faux", afficher);
                CHECK(afficher == false);
            }
        }
    }
}
