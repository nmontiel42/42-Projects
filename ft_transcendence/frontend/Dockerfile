FROM node:18-alpine AS build

WORKDIR /app

COPY package*.json ./

RUN npm install

COPY . .

RUN npx @tailwindcss/cli -i ./css/style.css -o ./dist/output.css

RUN npm run build

FROM nginx:alpine

COPY --from=build /app /usr/share/nginx/html

EXPOSE 80 443

RUN mkdir /etc/ssl/nginx-certs

COPY ./conf/* ./
RUN mv /etc/nginx/conf.d/default.conf /etc/nginx/conf.d/default.conf.old

RUN cp default.conf /etc/nginx/conf.d/
RUN mv nginx-selfsigned.key /etc/ssl/nginx-certs/
RUN mv nginx-selfsigned.crt /etc/ssl/nginx-certs/

CMD ["nginx", "-g", "daemon off;"]