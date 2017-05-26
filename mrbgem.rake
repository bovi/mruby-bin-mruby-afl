MRuby::Gem::Specification.new('mruby-bin-mruby-afl') do |spec|
  spec.license = 'MIT'
  spec.author  = 'Daniel Bovensiepen <daniel@bovensiepen.net>'
  spec.summary = 'mruby interpreter in american fuzzy lop persistent mode'
  spec.bins = %w(mruby-afl)
  spec.add_dependency('mruby-compiler', :core => 'mruby-compiler')
end
