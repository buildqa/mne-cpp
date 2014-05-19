#ifndef STCMODEL_H
#define STCMODEL_H

#include <QAbstractTableModel>


//*************************************************************************************************************
//=============================================================================================================
// Eigen INCLUDES
//=============================================================================================================

#include <Eigen/Core>


//*************************************************************************************************************
//=============================================================================================================
// FORWARD DECLARATIONS
//=============================================================================================================

namespace MNELIB
{
    class MNESourceEstimate;
}


//*************************************************************************************************************
//=============================================================================================================
// USED NAMESPACES
//=============================================================================================================

using namespace Eigen;
using namespace MNELIB;


class StcModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    StcModel(QObject *parent = 0);

    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const ;
    virtual int columnCount(const QModelIndex &parent = QModelIndex()) const;
    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

    void addData(const MNESourceEstimate &stc);

private:
    QVector<VectorXd> m_data;   /**< List that holds the fiff matrix data <n_channels x n_samples> */


    qint32 m_iDownsampling;     /**< Down sampling factor */
    qint32 m_iCurrentSample;    /**< Downsampling */

};

#endif // STCMODEL_H