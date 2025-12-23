#include "doctest.h"
#include "EvaluationSecondeChance.h"
#include "QuestionTexte.h"
#include <memory>
#include <vector>

std::unique_ptr<EvaluationSecondeChance> initialiserEval() {
    std::vector<std::unique_ptr<Question>> questions;
    questions.push_back(std::make_unique<QuestionTexte>("Q1", "Capitale France?", "Paris"));
    return std::make_unique<EvaluationSecondeChance>(std::move(questions));
}

SCENARIO("L'évaluation offre une seconde chance en cas d'erreur") {

    GIVEN("Une évaluation avec une question") {
        auto eval = initialiserEval();
        bool afficherReponse = false;

        WHEN("L'utilisateur se trompe une première fois") {
            bool resultat = eval->repondre("Lyon", afficherReponse);

            THEN("Le test échoue mais on ne doit PAS afficher la bonne réponse") {
                CHECK_FALSE(resultat);
                CHECK(afficherReponse == false);
            }

            AND_WHEN("L'utilisateur réussit à sa deuxième chance") {
                resultat = eval->repondre("Paris", afficherReponse);

                THEN("L'assertion est vraie et le score augmente") {
                    REQUIRE(resultat == true);
                    CHECK(eval->nombreBonnesReponses() == 1);
                }
            }
        }

        WHEN("L'utilisateur se trompe deux fois de suite") {
            eval->repondre("Erreur 1", afficherReponse);
            bool resultatFinal = eval->repondre("Erreur 2", afficherReponse);

            THEN("L'échec est définitif et on affiche la solution") {
                CHECK(resultatFinal == false);
                CHECK(afficherReponse == true);
            }
        }
    }
}
