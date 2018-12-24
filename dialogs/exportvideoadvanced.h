#ifndef EXPORTVIDEOADVANCED_H
#define EXPORTVIDEOADVANCED_H

#include <QDialog>

class ExportVideoAdvanced : public QDialog {
public:
    ExportVideoAdvanced(QWidget* parent, int vcodec);
    int video_codec;
};

#endif // EXPORTVIDEOADVANCED_H
