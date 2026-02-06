Dinamik Sinüsoidal LED Dizisi

Bu proje, Arduino kullanarak 10 adet LED üzerinde matematiksel bir sinüs dalgası fonksiyonu koşturan ve dalga frekansını potansiyometre (analog giriş) ile 
gerçek zamanlı manipüle eden bir gömülü yazılım uygulamasıdır.
Sistem, PWM (Pulse Width Modulation) sinyallerini statik bir döngü yerine, zaman ve dış parametreye bağlı trigonometrik bir denklem üzerinden hesaplar.
Bu, LED'lerin nefes alma (breathing) veya dalgalanma efektini "prosedürel" olarak oluşturmasını sağlar.
-Proje Amacı
Sinyal Üretimi: Mikrodenetleyici içerisinde matematiksel fonksiyonlar kullanarak analog benzeri (DAC emülasyonu) çıktılar üretmek.

Dinamik Modülasyon: millis() zamanlayıcısı ve analogRead() girdisi ile sinyal frekansını kaotik/lineer olmayan bir yapıda değiştirmek.

Dizi Yönetimi: Çoklu çıkış pinlerini (4-13) döngüsel algoritmalarla yönetmek.
-Donanım Gereksinimleri
Mikrodenetleyici: Arduino Uno / Nano (veya ATmega328P tabanlı herhangi bir kart)

Aktüatörler: 10x LED (Dirençleri ile birlikte)

Giriş: 1x Potansiyometre (10k - 100k)

Bağlantı:

LED'ler: Dijital Pin 4 - 13

Potansiyometre: Analog Pin A2
Matematiksel Model (The Math Behind)

LED parlaklığı (
𝑃𝑊𝑀𝑣𝑎𝑙
PWM
val
	​

), aşağıdaki sinüzoidal transfer fonksiyonu kullanılarak hesaplanmaktadır:

𝑃𝑊𝑀(𝑡)=𝐴⋅(1+sin⁡(⋅𝑡+𝜑))       PWM(t)=A⋅(1+sin(ω⋅t+φ))

Bu ifade sayesinde LED parlaklığı zamanla 0–255 PWM aralığında düzgün ve periyodik olarak değişmektedir.

Kodda Gerçeklenen İfade
127.5 * (1.0 + sin(0.00628318 * float(analogRead(2) * millis() + 628318)))

Parametrelerin Açıklaması

Genlik (𝐴A):𝐴=127.5
A=127.5

Sinüs dalgasını [−1,1]
[−1,1] aralığından PWM için gerekli olan 0–255 0–255 aralığına ölçekler.
Açısal Frekans (𝜔):𝜔=0.00628318≈2𝜋/1000  ω=0.00628318

	​
Milisaniye cinsinden zamanı radyan cinsine çevirerek sinüs fonksiyonunun doğru periyotta çalışmasını sağlar.

Zaman ve Frekans Modülasyonu (t):𝑡=analogRead(2)×millis()t=analogRead(2)×millis()

Potansiyometreden okunan değer ile zaman çarpılarak sinüs dalgasının frekansı dinamik olarak ayarlanır.
Bu sayede kullanıcı, LED’in parlaklık değişim hızını gerçek zamanlı kontrol edebilir.

Faz Kayması (𝜑):𝜑=628318
φ=628318

Başlangıç fazını belirleyerek dalganın ilk anda hangi noktadan başlayacağını kontrol eder.
