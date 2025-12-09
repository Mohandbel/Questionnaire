#include"Question.h"
#include<string>
#include<iostream>
Question::Question(std::string intitule, std::string texte):
	d_intitule{intitule},d_texte{texte}
{}
std::string Question::getIntitule()const
{
	return d_intitule;
}
std::string Question::getTexte()const
{
	return d_texte;
}
void Question::AfficherQuestion()const
{
	std::cout << "Intitulé : " << d_intitule << std::endl;
	std::cout << "Question : " << d_texte << std::endl;
}