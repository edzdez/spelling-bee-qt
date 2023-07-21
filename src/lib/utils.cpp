#include "utils.h"

std::pair<double, QString> ranks[] = {
    {0.70, "Queen Bee"}, {0.50, "Outstanding"}, {0.40, "Marvellous"}, {0.25, "Superb"}, {0.15, "Excellent"},
    {0.08, "Skilled"},   {0.05, "Fine"},        {0.02, "Novice"},     {0.0, "Newbie"},
};

int lib::calculatePoints(QString &word)
{
    if (word.length() == 4)
        return 1;
    return word.length();
}

QString lib::calculateRank(int points, int total)
{
    double value = static_cast<double>(points) / total;
    for (const auto &[threshold, rank] : ranks)
    {
        if (value >= threshold)
            return rank;
    }

    Q_ASSERT(false);
}