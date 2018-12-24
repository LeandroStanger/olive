#include "exportvideoadvanced.h"

#include <QGridLayout>
#include <QLabel>
#include <QDialogButtonBox>
#include <QComboBox>

extern "C" {
    #include <libavcodec/avcodec.h>
}

ExportVideoAdvanced::ExportVideoAdvanced(QWidget *parent, int vcodec) :
    QDialog(parent),
    video_codec(vcodec)
{
    QGridLayout* layout = new QGridLayout(this);
    setLayout(layout);

    int row = 0;

    layout->addWidget(new QLabel("Bit Depth (bppc):"), row, 0);

    QComboBox* bit_depth_box = new QComboBox(this);
    bit_depth_box->addItem("8-bit", 8);
    bit_depth_box->addItem("10-bit", 10);
    bit_depth_box->addItem("12-bit", 12);
    bit_depth_box->addItem("16-bit", 16);
    layout->addWidget(bit_depth_box, row, 1);

    row++;

    if (video_codec == AV_CODEC_ID_H264) {
        layout->addWidget(new QLabel("Hardware Acceleration:"), 1, 0);

        QComboBox* h264_accel = new QComboBox(this);
        h264_accel->addItem("NVENC/CUDA");
        h264_accel->addItem("VAAPI");
        h264_accel->addItem("None (software/x264)");
        layout->addWidget(h264_accel, 1, 1);

        row++;
    }

    QDialogButtonBox* buttons = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    buttons->setCenterButtons(true);
    layout->addWidget(buttons, row, 0, 1, 2);

    connect(buttons, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttons, SIGNAL(rejected()), this, SLOT(reject()));
}
