Pod::Spec.new do |s|
  s.name             = 'PJCategory'
  s.version          = '0.1.1'
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

  s.source_files = 'Source/Class/**/*'

end

