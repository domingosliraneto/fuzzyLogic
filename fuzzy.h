#ifndef FUZZY_H
#define FUZZY_H

#include "SistemasdeControle/headers/modelLibs/model.h"
#include "triangular.h"
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h"
#include <vector>
#include <map>

namespace ModelHandler {
    template <typename Type>
        class Fuzzy: public Model<Type>
        {
            std::map< std::string, std::map< std::string, advancedModelHandler::MembershipFunction<Type>* > > InputMF;
            std::map< std::string, std::map< std::string, advancedModelHandler::MembershipFunction<Type>* > > outputMF;
            LinAlg::Matrix<unsigned> rules;
            LinAlg::Matrix<Type> fuzzyficatedValue;

        public:

            void addInputMF(std::string InputName,
                            std::string MFName,
                            advancedModelHandler::MembershipFunction<Type>* MF);

            std::map<std::string, advancedModelHandler::MembershipFunction<Type>*> getInputMF(std::string InputName);

            void addOutputMF(unsigned nOutput,
                            std::string MFName,
                            const advancedModelHandler::MembershipFunction<Type>* MF);

            void removeInputMF(unsigned nInput,
                            std::string MFName,
                            const advancedModelHandler::MembershipFunction<Type>* MF);
            void removeOutputMF(unsigned nOutput,
                            std::string MFName,
                            const advancedModelHandler::MembershipFunction<Type>* MF);


            void addRules();

            void removeRules();

            void fuzzyfication();

            void rulesExecute();

            void defuzzyfication();

            Type         sim(Type x){}
            Type         sim(Type x, Type y){}
            LinAlg::Matrix<Type> sim(LinAlg::Matrix<Type> x){}
            LinAlg::Matrix<Type> sim(Type lmin, Type lmax, Type step){}
            LinAlg::Matrix<Type> sim(LinAlg::Matrix<Type> x, LinAlg::Matrix<Type> y){}

            std::string print(){}
            unsigned getNumberOfVariables() const{}
            unsigned getNumberOfInputs() const{}
            unsigned getNumberOfOutputs() const{}
            void setLinearVector(LinAlg::Matrix<Type> Input, LinAlg::Matrix<Type> Output){}
            void setLinearModel(LinAlg::Matrix<Type> Input, LinAlg::Matrix<Type> Output){}

            Fuzzy(){}
        private:
//            getInputNames();
//            getMFNames(std::string InputName)

        };
}
#include "fuzzy.hpp"
#endif // FUZZY_H