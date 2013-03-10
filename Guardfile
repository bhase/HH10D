# A sample Guardfile
# More info at https://github.com/guard/guard#readme

# Add files and commands to this file, like the example:
#   watch(%r{file/path}) { `command(s)` }
#
guard 'shell' do
  watch(%r{.+\.cpp$|.+\.c$|.+\.h$}) {|m|
    img = :pending
    result = `make`
    if $?.exitstatus == 0
      img = :success
    elsif $?.exitstatus == 2
      img = :failed
    end
    n("#{result}", result.lines.to_a[-2], img)
  }
end
