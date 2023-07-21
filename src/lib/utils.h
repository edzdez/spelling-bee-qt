#ifndef SPELLING_BEE_QT_UTILS_H
#define SPELLING_BEE_QT_UTILS_H

#include <utility>

#include <QString>

namespace lib
{

int calculatePoints(QString &word);
QString calculateRank(int points, int total);

} // namespace lib

#endif // SPELLING_BEE_QT_UTILS_H
