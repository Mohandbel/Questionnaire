#include "Execute.h"
#include "QuestionTexte.h"
#include "QuestionNumerique.h"
#include "QuestionQCM.h"
#include <iostream>
#include <limits>
#include <sstream>
#include <vector>

Execute::Execute() : d_questionnaire(nullptr), d_questionnaireExiste(false) {
}

void Execute::lancer() {
    std::cout << "========================================" << std::endl;
    std::cout << "   SYSTEME DE GESTION DE QUESTIONNAIRE  " << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << std::endl;

    bool continuer = true;
    while (continuer) {
        afficherMenuPrincipal();
        int choix = lireChoix(1, 9);

        switch (choix) {
        case 1:
            creerQuestionnaire();
            break;
        case 2:
            if (d_questionnaireExiste) {
                ajouterQuestion();
            }
            else {
                std::cout << "Veuillez d'abord creer un questionnaire (option 1)." << std::endl;
                attendreEntree();
            }
            break;
        case 3:
            if (d_questionnaireExiste) {
                afficherQuestionnaire();
            }
            else {
                std::cout << "Aucun questionnaire disponible." << std::endl;
                attendreEntree();
            }
            break;
        case 4:
            if (d_questionnaireExiste) {
                lancerApprentissage();
            }
            else {
                std::cout << "Aucun questionnaire disponible." << std::endl;
                attendreEntree();
            }
            break;
        case 5:
            if (d_questionnaireExiste) {
                lancerEvaluation();
            }
            else {
                std::cout << "Aucun questionnaire disponible." << std::endl;
                attendreEntree();
            }
            break;
        case 6:
            if (d_questionnaireExiste) {
                sauvegarderQuestionnaire();
            }
            else {
                std::cout << "Aucun questionnaire disponible." << std::endl;
                attendreEntree();
            }
            break;
        case 7:
            chargerQuestionnaire();
            break;
        case 8:
            if (d_questionnaireExiste) {
                std::cout << "Nombre de questions dans le questionnaire: "
                    << d_questionnaire->nombreQuestions() << std::endl;
                attendreEntree();
            }
            else {
                std::cout << "Aucun questionnaire disponible." << std::endl;
                attendreEntree();
            }
            break;
        case 9:
            std::cout << "Au revoir !" << std::endl;
            continuer = false;
            break;
        default:
            std::cout << "Choix invalide." << std::endl;
            attendreEntree();
            break;
        }
    }
}

void Execute::afficherMenuPrincipal() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "            MENU PRINCIPAL" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "1. Creer un nouveau questionnaire" << std::endl;
    std::cout << "2. Ajouter une question" << std::endl;
    std::cout << "3. Afficher le questionnaire" << std::endl;
    std::cout << "4. Lancer l'apprentissage" << std::endl;
    std::cout << "5. Lancer une evaluation" << std::endl;
    std::cout << "6. Sauvegarder le questionnaire" << std::endl;
    std::cout << "7. Charger un questionnaire" << std::endl;
    std::cout << "8. Afficher le nombre de questions" << std::endl;
    std::cout << "9. Quitter" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "Votre choix (1-9): ";
}

int Execute::lireChoix(int min, int max) {
    int choix;
    while (!(std::cin >> choix) || choix < min || choix > max) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Choix invalide. Veuillez entrer un nombre entre "
            << min << " et " << max << ": ";
    }
    std::cin.ignore(); // Ignorer le '\n' restant
    return choix;
}

std::string Execute::lireLigne(const std::string& prompt) {
    std::string ligne;
    std::cout << prompt;
    std::getline(std::cin, ligne);
    return ligne;
}

int Execute::lireEntier(const std::string& prompt) {
    int valeur;
    std::cout << prompt;
    while (!(std::cin >> valeur)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Valeur invalide. " << prompt;
    }
    std::cin.ignore(); // Ignorer le '\n' restant
    return valeur;
}

void Execute::attendreEntree() {
    std::cout << "\nAppuyez sur Entree pour continuer...";
    std::cin.ignore();
}

void Execute::creerQuestionnaire() {
    std::string titre = lireLigne("Entrez le titre du questionnaire: ");
    d_questionnaire = std::make_unique<Questionnaire>(titre);
    d_questionnaireExiste = true;
    std::cout << "Questionnaire cree avec succes !" << std::endl;
    attendreEntree();
}

void Execute::ajouterQuestion() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "      TYPE DE QUESTION A AJOUTER" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "1. Question texte" << std::endl;
    std::cout << "2. Question numerique" << std::endl;
    std::cout << "3. Question QCM" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "Votre choix (1-3): ";

    int type = lireChoix(1, 3);

    switch (type) {
    case 1:
        ajouterQuestionTexte();
        break;
    case 2:
        ajouterQuestionNumerique();
        break;
    case 3:
        ajouterQuestionQCM();
        break;
    }
}

void Execute::ajouterQuestionTexte() {
    std::string intitule = lireLigne("Entrez l'intitule de la question: ");
    std::string texte = lireLigne("Entrez le texte de la question: ");
    std::string bonneReponse = lireLigne("Entrez la bonne reponse: ");

    auto question = std::make_unique<QuestionTexte>(intitule, texte, bonneReponse);
    d_questionnaire->ajouterQuestion(std::move(question));
    std::cout << "Question texte ajoutee avec succes !" << std::endl;
    attendreEntree();
}

void Execute::ajouterQuestionNumerique() {
    std::string intitule = lireLigne("Entrez l'intitule de la question: ");
    std::string texte = lireLigne("Entrez le texte de la question: ");
    int bonneReponse = lireEntier("Entrez la bonne reponse (nombre entier): ");
    int min = lireEntier("Entrez la valeur minimum: ");
    int max = lireEntier("Entrez la valeur maximum: ");

    auto question = std::make_unique<QuestionNumerique>(intitule, texte, bonneReponse, min, max);
    d_questionnaire->ajouterQuestion(std::move(question));
    std::cout << "Question numerique ajoutee avec succes !" << std::endl;
    attendreEntree();
}

void Execute::ajouterQuestionQCM() {
    std::string intitule = lireLigne("Entrez l'intitule de la question: ");
    std::string texte = lireLigne("Entrez le texte de la question: ");

    std::vector<std::string> propositions;
    std::cout << "Entrez 4 propositions:" << std::endl;
    for (int i = 1; i <= 4; ++i) {
        std::string prop = lireLigne("Proposition " + std::to_string(i) + ": ");
        propositions.push_back(prop);
    }

    int bonneReponse = lireEntier("Entrez le numero de la bonne reponse (1-4): ");
    if (bonneReponse < 1 || bonneReponse > 4) {
        std::cout << "Numero invalide. Utilisation de 1 par defaut." << std::endl;
        bonneReponse = 1;
    }

    auto question = std::make_unique<QuestionQCM>(intitule, texte, propositions, bonneReponse);
    d_questionnaire->ajouterQuestion(std::move(question));
    std::cout << "Question QCM ajoutee avec succes !" << std::endl;
    attendreEntree();
}

void Execute::afficherQuestionnaire() {
    std::cout << std::endl;
    d_questionnaire->afficher();
    attendreEntree();
}

void Execute::sauvegarderQuestionnaire() {
    std::string nomFichier = lireLigne("Entrez le nom du fichier pour sauvegarder: ");
    std::ofstream fichier(nomFichier);

    if (!fichier.is_open()) {
        std::cout << "Erreur: Impossible d'ouvrir le fichier pour ecriture." << std::endl;
        attendreEntree();
        return;
    }

    d_questionnaire->ecrire(fichier);
    fichier.close();
    std::cout << "Questionnaire sauvegarde avec succes dans " << nomFichier << std::endl;
    attendreEntree();
}

void Execute::chargerQuestionnaire() {
    std::string nomFichier = lireLigne("Entrez le nom du fichier a charger: ");
    std::ifstream fichier(nomFichier);

    if (!fichier.is_open()) {
        std::cout << "Erreur: Impossible d'ouvrir le fichier " << nomFichier << std::endl;
        attendreEntree();
        return;
    }

    try {
        d_questionnaire = std::make_unique<Questionnaire>();
        d_questionnaire->lire(fichier);
        d_questionnaireExiste = true;
        fichier.close();
        std::cout << "Questionnaire charge avec succes !" << std::endl;
        std::cout << "Titre: " << d_questionnaire->titre() << std::endl;
        std::cout << "Nombre de questions: " << d_questionnaire->nombreQuestions() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Erreur lors du chargement: " << e.what() << std::endl;
        d_questionnaireExiste = false;
    }

    attendreEntree();
}

void Execute::lancerApprentissage() {
    if (d_questionnaire->estVide()) {
        std::cout << "Le questionnaire est vide. Ajoutez des questions d'abord." << std::endl;
        attendreEntree();
        return;
    }

    std::cout << "\n========================================" << std::endl;
    std::cout << "         MODE APPRENTISSAGE" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "Titre du questionnaire: " << d_questionnaire->titre() << std::endl;
    std::cout << std::endl;

    for (std::size_t i = 0; i < d_questionnaire->nombreQuestions(); ++i) {
        const Question& question = d_questionnaire->question(i);

        std::cout << "----------------------------------------" << std::endl;
        std::cout << "Question " << (i + 1) << " sur "
            << d_questionnaire->nombreQuestions() << std::endl;
        std::cout << "----------------------------------------" << std::endl;

        // Afficher le titre (intitulé) et la question
        question.AfficherQuestion();
        std::cout << std::endl;

        // Afficher la bonne réponse
        std::cout << "Reponse: ";
        question.AfficherReponse();
        std::cout << std::endl;

        // Attendre que l'utilisateur appuie sur Entrée pour passer à la question suivante
        if (i < d_questionnaire->nombreQuestions() - 1) {
            attendreEntree();
        }
    }

    std::cout << "========================================" << std::endl;
    std::cout << "     FIN DE L'APPRENTISSAGE" << std::endl;
    std::cout << "========================================" << std::endl;
    attendreEntree();
}

void Execute::lancerEvaluation() {
    if (d_questionnaire->estVide()) {
        std::cout << "Le questionnaire est vide. Ajoutez des questions d'abord." << std::endl;
        attendreEntree();
        return;
    }

    std::cout << "\n========================================" << std::endl;
    std::cout << "      TYPE D'EVALUATION" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "1. Evaluation Test (une seule tentative)" << std::endl;
    std::cout << "2. Evaluation Adaptative" << std::endl;
    std::cout << "3. Evaluation Deuxieme Chance" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "Votre choix (1-3): ";

    int type = lireChoix(1, 3);

    switch (type) {
    case 1:
        lancerEvaluationTest();
        break;
    case 2:
        lancerEvaluationAdaptative();
        break;
    case 3:
        lancerEvaluationDeuxiemeChance();
        break;
    }
}

std::vector<std::unique_ptr<Question>> Execute::creerCopiesQuestions() {
    std::vector<std::unique_ptr<Question>> copies;

    for (std::size_t i = 0; i < d_questionnaire->nombreQuestions(); ++i) {
        const Question& q = d_questionnaire->question(i);

        // Utiliser dynamic_cast pour identifier le type de question
        if (const QuestionTexte* qt = dynamic_cast<const QuestionTexte*>(&q)) {
            copies.push_back(std::make_unique<QuestionTexte>(
                qt->getIntitule(),
                qt->getTexte(),
                qt->bonneReponse()
            ));
        }
        else if (const QuestionNumerique* qn = dynamic_cast<const QuestionNumerique*>(&q)) {
            copies.push_back(std::make_unique<QuestionNumerique>(
                qn->getIntitule(),
                qn->getTexte(),
                qn->bonneReponse(),
                qn->min(),
                qn->max()
            ));
        }
        else if (const QuestionQCM* qqcm = dynamic_cast<const QuestionQCM*>(&q)) {
            copies.push_back(std::make_unique<QuestionQCM>(
                qqcm->getIntitule(),
                qqcm->getTexte(),
                qqcm->propositions(),
                qqcm->bonneReponse()
            ));
        }
    }

    return copies;
}

void Execute::lancerEvaluationTest() {
    std::vector<std::unique_ptr<Question>> questions = creerCopiesQuestions();
    EvaluationTest evaluation(std::move(questions));
    executerEvaluation(evaluation);
}

void Execute::lancerEvaluationAdaptative() {
    std::vector<std::unique_ptr<Question>> questions = creerCopiesQuestions();
    EvaluationAdaptative evaluation(std::move(questions));
    executerEvaluation(evaluation);
}

void Execute::lancerEvaluationDeuxiemeChance() {
    std::vector<std::unique_ptr<Question>> questions = creerCopiesQuestions();
    EvaluationSecondeChance evaluation(std::move(questions));
    executerEvaluation(evaluation);
}

void Execute::executerEvaluation(Evaluation& evaluation) {
    std::cout << "\n========================================" << std::endl;
    std::cout << "         DEBUT DE L'EVALUATION" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << std::endl;

    int numeroQuestion = 1;
    while (evaluation.aEncoreQuestions()) {
        Question* question = evaluation.questionCourante();
        if (!question) {
            break;
        }

        std::cout << "Question " << numeroQuestion
            << " sur " << evaluation.nombreQuestions() << std::endl;
        question->AfficherQuestion();
        std::cout << std::endl;

        std::string reponse = lireLigne("Votre reponse: ");

        bool afficherBonneReponse = false;
        bool correcte = evaluation.repondre(reponse, afficherBonneReponse);

        if (correcte) {
            std::cout << "Bravo ! Bonne reponse !" << std::endl;
            evaluation.questionSuivante();
            numeroQuestion++;
        }
        else {
            std::cout << "Mauvaise reponse." << std::endl;
            if (afficherBonneReponse) {
                question->AfficherReponse();
            }
            evaluation.questionSuivante();
            numeroQuestion++;
        }

        std::cout << std::endl;
    }

    std::cout << "========================================" << std::endl;
    std::cout << "         FIN DE L'EVALUATION" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "Nombre de bonnes reponses: " << evaluation.nombreBonnesReponses()
        << " / " << evaluation.nombreQuestions() << std::endl;
    std::cout << "Nombre total d'essais: " << evaluation.nombreEssais() << std::endl;

    double pourcentage = (evaluation.nombreQuestions() > 0) ?
        (100.0 * evaluation.nombreBonnesReponses() / evaluation.nombreQuestions()) : 0.0;
    std::cout << "Score: " << pourcentage << "%" << std::endl;
    std::cout << "========================================" << std::endl;

    attendreEntree();
}
