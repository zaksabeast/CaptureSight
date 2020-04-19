#! usr/bin/env ruby
require 'json'
require 'fileutils'

$pokespriteDir = "../../../pokesprite"
$spriteDir = "../../romfs/pokemon-sprites_"

spriteData = JSON.parse(File.open("#{$pokespriteDir}/data/pokemon.json", "r").read)

class String
    def form_pfx() (["$", "female"].include? self) ? "" : "-#{self}" end

    def src_str pokemon
        "#{self == "female" ? "female/" : ""}#{pokemon["slug"]["eng"]}#{form_pfx}"
    end
end

class Numeric
    def form_pfxi form_name
        if form_name == "gmax" then "g"
        elsif self == 0 then ""
        else "-#{self}" end
    end
end

class Array
    def forms_to_src_target(pokemon)
        flat_map.each_with_index do |form, ix|
            [["#{$pokespriteDir}/pokemon-gen8/shiny/#{form.src_str pokemon}.png",
              "#{$spriteDir}/#{pokemon["idx"]}#{ix.form_pfxi form}s.png"],
             ["#{$pokespriteDir}/pokemon-gen8/regular/#{form.src_str pokemon}.png",
              "#{$spriteDir}/#{pokemon["idx"]}#{ix.form_pfxi form}.png"]]
        end
    end
end

spriteData.values.flat_map do |pokemon|
    pokemon["gen-8"]["forms"]["female"] = {} if pokemon["gen-8"]["forms"]["$"]["has_female"]
    pokemon["gen-8"]["forms"] # ubuntu 16.04 is stuck with ruby 2.3 I can't use filter
        .entries.reject { |_, v| v["is_alias_of"] }.map(&:first) # poor man's `filter {}.keys`
        .forms_to_src_target pokemon
end.each {|src, dst| FileUtils.cp src, dst}

# runtime: 16 seconds