#ifndef MYVIDEOSURFACE_H
#define MYVIDEOSURFACE_H

#include <QAbstractVideoSurface>

class MyVideoSurface  : public QAbstractVideoSurface
{
	Q_OBJECT

public:
	MyVideoSurface(QObject *parent = 0);

	// 支持像素的格式
	QList<QVideoFrame::PixelFormat> supportedPixelFormats(QAbstractVideoBuffer::HandleType 
		handleType = QAbstractVideoBuffer::NoHandle) const override;

	// 检测视频流的格式是否合法
	bool isFormatSupported(const QVideoSurfaceFormat& format) const override;
	bool start(const QVideoSurfaceFormat& format) override;
	bool present(const QVideoFrame& frame) override;
	QRect videoRect() const;
	void updateVideoRect();
	void paint(QPainter* painter);
	~MyVideoSurface();

signals:
	void frameAvailable(QVideoFrame);

//private:
//	QWidget* widet_;
//	QImage::Format imageFormat_;
//	QRect taretRect_;
//	QSize imageSize_;
//	QVideoFrame currentFrame_;
};

#endif // !MYVIDEOSURFACE_H
