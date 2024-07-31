
#include "src/bend/man/mancloud.h"
#include "src/bend/man/mandb.h"
#include "src/fend/uimain/uimain.h"
#include <QApplication>
#include <src/helper/filehelper.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 读取文件中的qss
    // 以":/"开头的表示是资源文件
    QString qssContent = FileHelper::readAllTxt(":/static/qss/default.qss");

    // QApplication加载qss的内容
    a.setStyleSheet(qssContent);


//    DaoBuckets buckets;
//    buckets.bucketsFromMock(":/static/testing/buckets1.json");



    UiMain w;

    MC->setBucket();
    MDB->init();


//    w.show();
    w.showLoginDialog();

    return a.exec();
}


//#include "cos_api.h"
//#include "cos_sys_config.h"
//#include "cos_defines.h"

//int main(int argc, char *argv[]) {
//    // 1. 指定配置文件路径，初始化 CosConfig
//    qcloud_cos::CosConfig config("D:/project/qt/cos_browser/config.json");
//    qcloud_cos::CosAPI cos(config);

//    // 2. 构造查询存储桶列表的请求
//    qcloud_cos::GetServiceReq req;
//    qcloud_cos::GetServiceResp resp;
//    qcloud_cos::CosResult result = cos.GetService(req, &resp);

//    // 3. 获取响应信息
//    const qcloud_cos::Owner& owner = resp.GetOwner();
//    const std::vector<qcloud_cos::Bucket>& buckets = resp.GetBuckets();
//    std::cout << "owner.m_id=" << owner.m_id << ", owner.display_name=" << owner.m_display_name << std::endl;

//    for (std::vector<qcloud_cos::Bucket>::const_iterator itr = buckets.begin(); itr != buckets.end(); ++itr) {
//        const qcloud_cos::Bucket& bucket = *itr;
//        std::cout << "Bucket name=" << bucket.m_name << ", location="
//                  << bucket.m_location << ", create_date=" << bucket.m_create_date << std::endl;
//    }

//    // 4. 处理调用结果
//    if (result.IsSucc()) {
//        // 查询存储桶列表成功
//    } else {
//        // 查询存储桶列表失败，可以调用 CosResult 的成员函数输出错误信息，例如 requestID 等
//        std::cout << "HttpStatus=" << result.GetHttpStatus() << std::endl;
//        std::cout << "ErrorCode=" << result.GetErrorCode() << std::endl;
//        std::cout << "ErrorMsg=" << result.GetErrorMsg() << std::endl;
//        std::cout << "ResourceAddr=" << result.GetResourceAddr() << std::endl;
//        std::cout << "XCosRequestId=" << result.GetXCosRequestId() << std::endl;
//        std::cout << "XCosTraceId=" << result.GetXCosTraceId() << std::endl;
//    }
//}
