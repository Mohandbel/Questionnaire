#ifndef EXECUTE_H
#define EXECUTE_H

#include "Questionnaire.h"
#include "evaluation.h"
#include "evaluation_test.h"
#include "evaluation_adaptative.h"
#include "evaluation_deuxieme_chance.h"
#include <memory>
#include <string>
#include <fstream>

class Execute {
public:
    Execute();
    ~Execute() = default;

    // Méthode principale pour lancer l'application
    void lancer();

private:
    // Menu principal
    void afficherMenuPrincipal();
    int lireChoix(int min, int max);


    // Gestion du questionnaire
    void creerQuestionnaire();
    void ajouterQuestion();
    void afficherQuestionnaire();
    void sauvegarderQuestionnaire();
    void chargerQuestionnaire();

    // Apprentissage
    void lancerApprentissage();

    // Évaluations
    void lancerEvaluation();
    void lancerEvaluationTest();
    void lancerEvaluationAdaptative();
    void lancerEvaluationDeuxiemeChance();
    void executerEvaluation(Evaluation& evaluation);

    // Utilitaires
    void attendreEntree();
    std::vector<std::unique_ptr<Question>> creerCopiesQuestions();

    std::unique_ptr<Questionnaire> d_questionnaire;
    std::string d_nomFichierCourant;
};

#endif // EXECUTE_H

