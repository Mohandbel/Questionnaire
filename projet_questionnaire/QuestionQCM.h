    #ifndef QUESTIONQCM_H
    #define QUESTIONQCM_H

    #include "Question.h"
    #include<vector>

    class QuestionQCM : public Question {
    public:
        QuestionQCM(const std::string& intitule,
            const std::string& texte,
            const std::vector<std::string>& propositions,
            int bonneReponse);

        bool verifierReponse(const std::string& rep) const override;
        void AfficherQuestion() const override;
        void AfficherReponse() const override;
        void ecrire(std::ostream& os) const override;

    private:
        std::vector<std::string> d_propositions;
        int d_bonneReponse;
    };

    #endif //QUESTIONQCM_H
