Pod::Spec.new do |s|
  s.name             = 'PJCategory'
  s.version          = '0.1.2'
  s.summary          = 'PJCategory'
  s.description      = <<-DESC
	                      some Category for iOS
                       DESC

  s.homepage         = 'https://github.com/xupeng48/pjcategory'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'xupeng' => '13585548248@163.com' }
  s.source           = { :git => 'https://github.com/xupeng48/pjcategory.git', :tag => s.version.to_s }
  s.ios.deployment_target = '8.0'
  s.requires_arc = true

  s.public_header_files = 'Source/Class/*.h'
  s.source_files = 'Source/Class/*.h'

  s.subspec 'Foundation' do |sf|
    sf.source_files = 'Source/Class/Foundation/*.{h,m}'
  end

  s.subspec 'UIKit' do |su|
    su.source_files = 'Source/Class/UIKit/*.{h,m}'
    su.dependency "PJCategory/Foundation"
  end

end

