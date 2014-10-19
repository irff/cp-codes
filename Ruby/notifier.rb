require 'open-uri'
require 'json'
require 'date'

def repeat_every(interval)
  Thread.new do
	loop do
	  start_time = Time.now
	  yield
	  elapsed = Time.now - start_time
	  sleep([interval - elapsed, 0].max)
    end
  end
end

class Date
	def Date.now
		return Date.jd(DateTime.now.jd)
	end
end

def check_file(idx, tanggalx, date_now, file_name)
	f = File.open(file_name)
	map = JSON.parse(f.read)
	
	found = false
	map.each { |id, expire|
		#puts "#{id} - #{expire}"
		tanggal_expire = Date.parse(expire)
		if(tanggal_expire < date_now)
			map.delete(id)
		end

		if(idx == id) 
			found = true
		end
	}
	if(!found)
		map[idx] = tanggalx
	end
	
	f = File.new(file_name, 'w')
	f.write(JSON.generate(map))
	f.close
	return found
end


thread = repeat_every(60) do 
	page = open('http://localhost/notifier/home/request/')
	teks = page.read
	events = JSON.parse(teks)
	event_size = events.size

	time_now = Time.now
	date_now = Date.now

	puts "Sistem notifikasi sedang berjalan. Current time: #{time_now}."

	a_day = 60 * 60 * 24

	for i in (0...event_size) do
		id 			= events[i]["Id"]
		jenis		= events[i]["Jenis"]
		dari 		= events[i]["Dari"]
		kepada		= events[i]["Kepada"]
		nama_acara	= events[i]["Nama_acara"]
		waktu		= events[i]["Waktu"]
		tempat		= events[i]["Tempat"]
		
		waktu 		= Time.parse(waktu);

		# id			= events[i]["id"]
		# deskripsi	= events[i]["deskripsi"]
		# tempat		= events[i]["tempat"]
		# tanggal		= Date.parse(events[i]["tanggal"])
		# jam			= Time.parse(events[i]["jam"])
		# jam_		= events[i]["jam"]
		# waktu		= Time.local(tanggal.year, tanggal.month, tanggal.day, jam.hour, jam.min, jam.sec)
		# #puts "#{tanggal.day} - #{tanggal.month} - #{tanggal.year}"

		tanggal = Date.new(waktu.year, waktu.month, waktu.day);
		jam = waktu.strftime("%R")
		#puts "#{date_now}  #{tanggal}"

		#puts i.to_s + " " + time_now.to_s
		#puts i.to_s + " " + waktu.to_s

		if(time_now <= waktu)
			if(tanggal - 7 == date_now)
				if(!check_file(id, tanggal, date_now, 'seminggu.json')) then
					system("msg * \"Seminggu lagi #{nama_acara} di #{tempat} pukul #{jam}\"")
				end
			elsif (tanggal - 1 == date_now)
				if(!check_file(id, tanggal, date_now, 'sehari.json')) then
					system("msg * \"Besok #{nama_acara} di #{tempat} pukul #{jam}\"")
				end
			elsif (waktu - time_now) <= 3600
				if(!check_file(id, tanggal, date_now, 'sejam.json')) then
					system("msg * \"Satu jam lagi #{nama_acara} di #{tempat} pukul #{jam}\"")
				end
			end
		end
	end

end

thread.join