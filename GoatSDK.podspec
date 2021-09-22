#
#  Be sure to run `pod spec lint GoatSDK.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |spec|
  spec.name         = "GoatSDK"
  spec.version      = "3.6.6"
  spec.summary      = "GoatSDK海外版"
  spec.description  = <<-DESC
			goatSDK是由高图公司提供的一套iOS海外手游发行类SDK
                   DESC
  spec.homepage     = "https://github.com/Romambo/GoatSDK_pod.git"
  #spec.license      = "MIT (example)"
  spec.license      = { :type => "MIT", :file => "LICENSE" }
  spec.author             = { "wang yibo" => "wangyibo@goatgames.com" }
  spec.source       = { :git => "https://github.com/Romambo/GoatSDK_pod.git", :tag => spec.version.to_s }
  spec.ios.deployment_target = '9.0'
  spec.static_framework = true
  spec.requires_arc = true
  spec.frameworks = 'SystemConfiguration', 'iAd','AdSupport','CoreTelephony','Accelerate','Foundation','UIKit'

  spec.pod_target_xcconfig =   {'OTHER_LDFLAGS' => ['-lObjC']}
  spec.libraries = 'c++', 'z', 'sqlite3'
  spec.pod_target_xcconfig = { 'VALID_ARCHS' => 'x86_64 armv7 armv7s arm64' }
  spec.default_subspecs = 'GoatSDK'


  spec.subspec 'GoatBasic' do |ss|
    ss.ios.deployment_target = '9.0'
    ss.vendored_frameworks = 'GoatSDK/GoatBasic.framework'
    ss.resource = 'GoatSDK/SVProgressHUD.bundle'
  end

  spec.subspec 'GoatUserCenter' do |ss|
    ss.ios.deployment_target = '9.0'
    ss.vendored_frameworks = 'GoatSDK/GoatUserCenter.framework'
    ss.resource = 'GoatSDK/GoatSource.bundle','GoatSdk_Version.json','GoatService-Info.plist'
  end

  spec.subspec 'GoatSDK' do |ss|
    ss.ios.deployment_target = '9.0'
    #ss.vendored_frameworks = 'GoatSDK/GoatSDK.framework'
    ss.resource = 'GoatSDK/GoatSource.bundle','GoatSdk_Version.json','GoatService-Info.plist'
  end

  spec.subspec 'TXIMSDKManager' do |ss|
    
    ss.ios.deployment_target = '9.0'
    ss.dependency 'GoatSDK/GoatSDK'
    ss.vendored_frameworks = 'GoatSDK/TXIMSDKManager.framework','GoatSDK/ImSDK_Plus.framework'
  end




  # ――― Resources ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  #
  #  A list of resources included with the Pod. These are copied into the
  #  target bundle with a build phase script. Anything else will be cleaned.
  #  You can preserve files from being cleaned, please don't preserve
  #  non-essential files like tests, examples and documentation.
  #

  # spec.resource  = "icon.png"
  # spec.resources = "Resources/*.png"

  # spec.preserve_paths = "FilesToSave", "MoreFilesToSave"


  # ――― Project Linking ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  #
  #  Link your library with frameworks, or libraries. Libraries do not include
  #  the lib prefix of their name.
  #

  # spec.framework  = "SomeFramework"
  # spec.frameworks = "SomeFramework", "AnotherFramework"

  # spec.library   = "iconv"
  # spec.libraries = "iconv", "xml2"


  # ――― Project Settings ――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  #
  #  If your library depends on compiler flags you can set them in the xcconfig hash
  #  where they will only apply to your library. If you depend on other Podspecs
  #  you can include multiple dependencies to ensure it works.

  # spec.requires_arc = true

  # spec.xcconfig = { "HEADER_SEARCH_PATHS" => "$(SDKROOT)/usr/include/libxml2" }
  # spec.dependency "JSONKit", "~> 1.4"

end
